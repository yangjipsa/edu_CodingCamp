//board : wemos d1 r1

#include "pitches.h"

int PIN_BUZ = D5;
int ArraySize = sizeof(Song_M)/sizeof(int);
                 
void setup()
{
   delay(5000);// song play after 5 sec
  
  for(int i=0; i<ArraySize; i++)
  {
    tone(PIN_BUZ,Song_M[i]);
    delay(Song_R[i]*200);
    noTone(PIN_BUZ);
  }
}

void loop() 
{
}
