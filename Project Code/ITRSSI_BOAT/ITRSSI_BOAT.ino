/***************************************************************
  TITLE :RSSI BOAT LOCALIZATION
        
****************************************************************/

/********************HEADER FILES*******************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#include<SoftwareSerial.h>
SoftwareSerial localhost(3, 4);
#include"motor.h"
#include"global.h"
#include"zone.h"
#include"audio.h"
#include"iot.h"

/***************************************************************/

/**********************FUNCTION DECLRATION***********************/
void F_iot_send(char*);
void F_SWITCH_ISR(void);
/****************************************************************/

void setup() {
  Serial.begin(9600);//BAUD RATE
  localhost.begin(9600); 
  E_ZONE_STATE = NO_ZONE;
  E_MOTOR_STATE = MOTOR_OFF;
  E_AUDIO_STATE = NO_AUDIO;
  E_IOT_STATE = NO_DATA;
    F_zone_state();
  F_audio_state();
  F_motor_state();
  pinMode(D_motor_positive, OUTPUT);
  pinMode(D_motor_negative, OUTPUT);
  pinMode(D_audio_moderate, OUTPUT);
  pinMode(D_audio_danger, OUTPUT);
  pinMode(D_switch, INPUT_PULLUP);
//  pinMode(D_ip_pin, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RSSI BOAT");
  lcd.setCursor(0, 1);
  lcd.print("LOCALIZATION");
  attachInterrupt(0, F_SWITCH_ISR, FALLING);
  delay(2000);  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HOTSPOT TO CONCT");
  lcd.setCursor(0, 1);
  lcd.print("   rssiboat");
  delay(5000);
  lcd.clear();
 // if (digitalRead(D_ip_pin) == LOW)
    F_localhost();
}
void loop() {
  F_zone_state();
  F_motor_state();
  F_audio_state();
  F_iot_state();
  delay(500);
}

void F_localhost(void)
{
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("waiting for ip");
  while (G_ip_flag == false) {
    int L_i = 0;
    while (localhost.available() > 0)
    {
      char L_d = (char)localhost.read();
      if (L_d == '#') {
        G_ip_flag = true;
        break;
      }
      lcd.setCursor(L_i, 0);
      lcd.print(L_d);
      L_i++;      
    }
  }
  delay(5000);
  lcd.clear();
}
void F_SWITCH_ISR(void)
{
  G_switch_flag = true;
  if (G_switch_flag == true)
  {
    E_ZONE_STATE = EMERGENCY;
    G_switch_flag = false;
  }
}
void serialEvent(void)
{
  while (Serial.available() > 0)
  {
    char L_c = (char)Serial.read();
    switch (L_c)
    {
      case 'A':
        E_ZONE_STATE = SAFE_ZONE;
        break;
      case 'B':
        E_ZONE_STATE = MODERATE_ZONE;
        break;
      case 'C':
        E_ZONE_STATE = DANGER_ZONE;
        break;
      default:
        E_ZONE_STATE = NO_ZONE;
        break;
    }
  }
}
