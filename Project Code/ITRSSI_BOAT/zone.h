#ifndef ZONE_H
#define ZONE_H
#include"global.h"
void F_zone_state(void);

void F_zone_state(void)
{
  switch (E_ZONE_STATE)
  {
    case NO_ZONE:
      E_AUDIO_STATE = NO_AUDIO;
      E_MOTOR_STATE = MOTOR_OFF;
      E_IOT_STATE = NO_DATA;
      E_PREV_ZONE = NO_ZONE;
      sprintf(G_array, "%-16s", G_zone_names[E_ZONE_STATE]);
      lcd.setCursor(0, 0);
      lcd.print(G_array);
      break;
    case SAFE_ZONE:
      E_AUDIO_STATE = NO_AUDIO;
      E_MOTOR_STATE = MOTOR_HIGH;
      E_IOT_STATE = NO_DATA;
      E_PREV_ZONE = SAFE_ZONE;
      sprintf(G_array, "%-16s", G_zone_names[E_ZONE_STATE]);
      lcd.setCursor(0, 0);
      lcd.print(G_array);
      break;
    case MODERATE_ZONE:
      E_AUDIO_STATE = AUDIO_MODERATE;
      E_MOTOR_STATE = MOTOR_MEDIUM;
      E_IOT_STATE = NO_DATA;
      E_PREV_ZONE = MODERATE_ZONE;
      sprintf(G_array, "%-16s", G_zone_names[E_ZONE_STATE]);
      lcd.setCursor(0, 0);
      lcd.print(G_array);
      break;
    case DANGER_ZONE:
      E_AUDIO_STATE = AUDIO_DANGER;
      E_MOTOR_STATE = MOTOR_SLOW;
      E_IOT_STATE = DANGER_DATA;
      E_PREV_ZONE = DANGER_ZONE;
      sprintf(G_array, "%-16s", G_zone_names[E_ZONE_STATE]);
      lcd.setCursor(0, 0);
      lcd.print(G_array);
      break;
    case EMERGENCY:
      sprintf(G_array, "%-16s", G_zone_names[E_ZONE_STATE]);
      lcd.setCursor(0, 0);
      lcd.print(G_array);
      E_IOT_STATE = EMERGENCY_DATA;      

      break;
  }
}

#endif
