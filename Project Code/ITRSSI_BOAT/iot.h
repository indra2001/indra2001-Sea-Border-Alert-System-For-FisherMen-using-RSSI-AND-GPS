#ifndef IOT_H
#define IOT_H
#include"global.h"
void F_iot_state(void);
void F_iot_send(char *message);

void F_iot_state(void)
{
  switch (E_IOT_STATE)
  {
    case DANGER_DATA:
      sprintf(G_array, "*%s#", G_zone_names[E_ZONE_STATE]);
      F_iot_send(G_array);     
      break;
    case EMERGENCY_DATA:
      sprintf(G_array, "*%s#", G_zone_names[E_ZONE_STATE]);
      F_iot_send(G_array);
      F_iot_send("*LAT:80.1236,LNG:259.124#");
      E_ZONE_STATE = E_PREV_ZONE;
      break;
    case NO_DATA:
      break;
  }
}
void F_iot_send(char *message)
{
  while (*message != '\0')
    Serial.write(*message++);
  delay(5000);
}
#endif
