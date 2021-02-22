#include <LiquidCrystal.h>

//LCD setup
const int rs = 8;
const int en = 7;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int redPot = A0;
const int greenPot = A1;
const int bluePot = A2;
const int whitePot = A3;

const int redLED = 9;
const int greenLED = 10;
const int blueLED = 11;
const int whiteLED = 6;

void setup(){
  lcd.begin(16, 2);
  pinMode(redPot,INPUT);
  pinMode(greenPot,INPUT);
  pinMode(bluePot,INPUT);
  pinMode(whitePot,INPUT);

  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(whiteLED,OUTPUT);

}

void loop(){
  //colour is the ADC read value
  //p_colour is the number as a percentage times 10
  int red;
  int green;
  int blue;
  int white;
  int p_red;
  int p_green;
  int p_blue;
  int p_white;
  
  red = analogRead(redPot);
  p_red = (int)(red/1.023);
  green = analogRead(greenPot);
  p_green = (int)(green/1.023);
  blue = analogRead(bluePot);
  p_blue = (int)(blue/1.023);
  white = analogRead(whitePot);
  p_white = (int)(white/1.023);

  

  analogWrite(redLED,red/4);
  analogWrite(greenLED,green/4);
  analogWrite(blueLED,blue/4);
  analogWrite(whiteLED,white/4);

  
  lcd.setCursor(0,0);
  lcd.print("R:");
  lcd.print(p_red/10);
  if (p_red != 1000){
      lcd.print(".");
      lcd.print(p_red%10);
  }
  lcd.print("% ");

  lcd.setCursor(8,0);
  lcd.print("G:");
  lcd.print(p_green/10);
  if (p_green != 1000){
      lcd.print(".");
      lcd.print(p_green%10);
  }
  lcd.print("% ");

  lcd.setCursor(0,1);
  lcd.print("B:");
  lcd.print(p_blue/10);
  if (p_blue != 1000){
      lcd.print(".");
      lcd.print(p_blue%10);
  }
  lcd.print("% ");

  lcd.setCursor(8,1);
  lcd.print("W:");
  lcd.print(p_white/10);
  if (p_white != 1000){
      lcd.print(".");
      lcd.print(p_white%10);
  }
  lcd.print("% ");  
  
  //Serial.println(red);
}
