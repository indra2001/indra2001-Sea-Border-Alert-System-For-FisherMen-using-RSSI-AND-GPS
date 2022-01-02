#ifndef AUDIO_H
#define AUDIO_H
#include"global.h"
void F_audio_state(void);

void F_audio_state(void)
{
  switch (E_AUDIO_STATE)
  {
    case NO_AUDIO:
      digitalWrite(D_audio_moderate, HIGH);
      digitalWrite(D_audio_danger, HIGH);
      break;
    case AUDIO_MODERATE:
      digitalWrite(D_audio_moderate, LOW);
      E_AUDIO_STATE = NO_AUDIO;
      break;
    case AUDIO_DANGER:
      digitalWrite(D_audio_danger, LOW);
      delay(500);
      digitalWrite(D_audio_danger,HIGH);
      E_AUDIO_STATE = NO_AUDIO;
      break;
  }
}
#endif
