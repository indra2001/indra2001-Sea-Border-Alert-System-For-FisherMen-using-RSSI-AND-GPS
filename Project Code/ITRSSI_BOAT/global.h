#ifndef GLOBAL_H
#define GLOBAL_H

/*********************#DEFINE VARIABLES*************************/
#define D_motor_positive 6
#define D_motor_negative 7
#define D_switch 2
#define D_audio_moderate A0
#define D_audio_danger A1
//#define D_ip_pin A5

/****************************************************************/
/********************GLOBAL VARIABLES****************************/
const char G_zone_names[5][17] = {"DANGER_ZONE", "MODERATE_ZONE", "SAFE_ZONE", "NO_ZONE", "EMERGENCY"};
char G_array[17] = {};
String G_localip="";
int G_i=0;
enum
{
  DANGER_ZONE = 0,
  MODERATE_ZONE = 1,
  SAFE_ZONE = 2,
  NO_ZONE = 3,
  EMERGENCY = 4
} E_ZONE_STATE,E_PREV_ZONE;
enum
{
  MOTOR_HIGH = 0,
  MOTOR_MEDIUM = 1,
  MOTOR_SLOW = 2,
  MOTOR_OFF = 3
} E_MOTOR_STATE;
enum {
  NO_AUDIO = 0,
  AUDIO_MODERATE = 1,
  AUDIO_DANGER = 2,
} E_AUDIO_STATE;

enum {
  NO_DATA = 0,
  DANGER_DATA = 1,
  EMERGENCY_DATA = 2
} E_IOT_STATE;
boolean G_switch_flag = false,G_ip_flag=false;
/****************************************************************/

#endif
