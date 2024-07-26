// board : wemos d1 r1
#define MAX_PWM 255

#define pinSW1  D2
#define pinSW2  D3
#define pinLED1 D4

bool cState1 = false; // current state of sw1
bool lState1 = false; // last state of sw1
bool cState2 = false; // current state of sw2
bool lState2 = false; // last state of sw2

int valLED1 = 0;

void setup()
{
  pinMode(pinSW1, INPUT);
  pinMode(pinSW2, INPUT);
  //Don't need to set pinMode() at pwm
} 

void loop() 
{
  cState1 = digitalRead(pinSW1); // read SW1 value
  cState2 = digitalRead(pinSW2); // read SW1 value
  delay(10); // for debouncing
  
  if (cState1 < lState1) // detecting rising edge
  {
    valLED1 = valLED1 + 30;
    if(valLED1 >= MAX_PWM) valLED1 = MAX_PWM;
    analogWrite(pinLED1, valLED1);
  }
  
  if (cState1 < lState1) // detecting rising edge
  {
    valLED1 = valLED1 - 30;
    if(valLED1 < 0) valLED1 = 0;
    analogWrite(pinLED1, valLED1);
  }
  
  lState1 = cState1; // sw1 value update
  lState2 = cState2; // sw1 value update
}
