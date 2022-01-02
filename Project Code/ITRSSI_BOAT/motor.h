#ifndef MOTOR_H
#define MOTOR_H
#include"global.h"
void F_motor_state(void);
void F_motor_state(void)
{
  switch (E_MOTOR_STATE)
  {
    case MOTOR_HIGH:
      analogWrite(D_motor_positive, 255);
      digitalWrite(D_motor_negative, LOW);
      break;
    case MOTOR_MEDIUM:
      analogWrite(D_motor_positive, 200);
      digitalWrite(D_motor_negative, LOW);
      break;
    case MOTOR_SLOW:
      analogWrite(D_motor_positive, 100);
      digitalWrite(D_motor_negative, LOW);
      break;
    case MOTOR_OFF:
      digitalWrite(D_motor_positive, LOW);
      digitalWrite(D_motor_negative, LOW);
      break;
  }
}
#endif
