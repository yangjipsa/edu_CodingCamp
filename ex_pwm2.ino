// board : wemos d1 r1
#define MAX_PWM 255

#define pinLED1 D5
#define pinLED2 D6

void setup(){} 
//Don't need to set pinMode() at pwm

void loop() 
{
  for(int i = 0; i < MAX_PWM; i++)  // 0 ~ 254
  { 
    analogWrite(pinLED1, i);
    analogWrite(pinLED2, i);
    delay(10); // 255번 * 10ms -> 약 2.5s
  }
  for(int i = 0; i < MAX_PWM; i++)  // 255 ~ 1
  {
    analogWrite(pinLED1, MAX_PWM - i);
    analogWrite(pinLED2, MAX_PWM - i);
    delay(10);   
  }
}
