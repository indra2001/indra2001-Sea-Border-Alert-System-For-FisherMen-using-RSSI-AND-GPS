
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
int Contrast = 75;
int buzzerPin = 7;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float lattitude,longitude; // create variable for latitude and longitude object 
SoftwareSerial gpsSerial(8,9);//tx, rx
TinyGPSPlus gps;// create gps object
void setup(){
//pinMode(buzzerPin, OUTPUT);
pinMode(13, OUTPUT);
//pinmode13= motor
digitalWrite(13, HIGH);
Serial.begin(9600); // connect serial
analogWrite(6, Contrast);
lcd.begin(16, 2);
gpsSerial.begin(9600); // connect gps sensor
lcd.print("GPS TRACKER");
delay(4000);
lcd.clear();
}
void loop(){
  
  
  while(1)
  {
   while (gpsSerial.available() > 0)
   { gps.encode(gpsSerial.read()); }

      if (gps.location.isUpdated())
      {
       Serial.print("LAT=");  Serial.println(gps.location.lat(), 6);
       Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
       lattitude=gps.location.lat();
       longitude=gps.location.lng();
      break;
      }
}
//serial.print on the serial monitor
 Serial.print("LATTITUDE="); Serial.println(lattitude,6);
 Serial.print("LONGITUDE="); Serial.println(longitude,6);
 lcd.setCursor(0, 0);
 lcd.print("LAT ");
 lcd.print(lattitude,6);
 delay(500);
 lcd.setCursor(0, 1);
 lcd.print("LONG ");
 lcd.print(longitude,6);
 delay(1000);
 lcd.clear();
 float pointlat,pointlong;

 pointlat= 13.030312;
 pointlong=80.221220;
 lattitude=gps.location.lat();
 longitude=gps.location.lng();
//if(lattitude<=13.03 && longitunmwde<=80.22)
if (abs(lattitude - pointlat) <1 && abs(longitude - pointlong)<1)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Border Reached");
  tone(buzzerPin, 1000);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(13, LOW);
  delay(60000);
}
}
