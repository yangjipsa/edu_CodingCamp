// board : wemos d1 r1
// library : 

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//Input I2C address after check address at the first parameter
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() 
{ 
  LCD_Cursor(); delay(1000); 
  lcd.clear(); delay(1000);

  LCD_Scroll(); delay(1000); 
  lcd.clear(); delay(1000);

  LCD_Align(); delay(1000); 
  lcd.clear(); delay(1000);
}

void LCD_Cursor(void)
{
  char temp[16] = "01234567abcdef";
  int Interval = 500;
  //lcd.noCursor();
  lcd.cursor();
  //lcd.noBlink();
  lcd.blink();
  
  for (int i=0; i<8 ; i++)
  {
    lcd.setCursor(2*i,0);
    delay(Interval);
    lcd.print(temp[i]);
  }

  for (int i=0; i<8 ; i++)
  {
    lcd.setCursor(2*i+1,1);
    delay(Interval);
    lcd.print(temp[i+8]);
  }
}

void LCD_Scroll(void)
{
  lcd.noCursor();
  lcd.noBlink();
  lcd.setCursor(0,0);
  lcd.print("hello");
  delay(500);
  for (int i=0 ; i<11 ; i++)
  {
    lcd.scrollDisplayRight();
    delay(500);
  }

  for (int i=0 ; i<11 ; i++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }
}

void LCD_Align(void)
{
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print("  Hello World!  ");
  delay(500);

  lcd.rightToLeft();
  lcd.setCursor(15,1);
  lcd.print("  Hello World!  ");
  delay(500);
}
