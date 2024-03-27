#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// put function declarations here:
int wiel1=4;
int wiel2=12;
int wiel3=3;
int wiel4=13;
int up=11;
int right=10;
int left=9;
int down=8;
int pot_waarde=0;
int duty_waarde=0;
int pin=A0;
boolean up_status = false;
boolean down_status= false;
boolean left_status= false;
boolean right_status=false;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(wiel1, OUTPUT);
  pinMode(wiel2, OUTPUT);
  pinMode(wiel3, OUTPUT);
  pinMode(wiel4, OUTPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  pinMode(pin, INPUT);
  analogWrite(wiel1,0);
  analogWrite(wiel2,0);
  analogWrite(wiel3,0);
  analogWrite(wiel4,0);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  up_status = digitalRead(up);
  down_status = digitalRead(down);
  left_status = digitalRead(left);
  right_status = digitalRead(right);
  pot_waarde = analogRead(pin);
  duty_waarde = map(pot_waarde, 0, 1023, 0, 255);
  if(up_status){
    
    Serial.println("Up");
    digitalWrite(wiel1, HIGH);
    digitalWrite(wiel2, HIGH);
    analogWrite(wiel1,duty_waarde);
    analogWrite(wiel2,duty_waarde);
    lcd.setCursor(0,0);
    lcd.print("Vooruit");
  }
  else if(up_status==0&& down_status==0&& left_status==0&&right_status==0){
    digitalWrite(wiel1, LOW);
    digitalWrite(wiel2, LOW);
    lcd.clear();
  }
   if(down_status){
    
    Serial.println("Down");
    digitalWrite(wiel3, HIGH);
    digitalWrite(wiel4, HIGH);
    analogWrite(wiel3,duty_waarde);
    analogWrite(wiel4,duty_waarde);
    lcd.setCursor(0,0);
    lcd.print("Achteruit");
  }
   else if(up_status==0&& down_status==0&& left_status==0&&right_status==0){
    digitalWrite(wiel3, LOW);
    digitalWrite(wiel4, LOW);
    lcd.clear();
  }
  if(left_status){
    
    Serial.println("Left");
    digitalWrite(wiel2, HIGH);
    digitalWrite(wiel4, HIGH);
    analogWrite(wiel2,duty_waarde);
    analogWrite(wiel4,duty_waarde);
    lcd.setCursor(0,0);
    lcd.print("Links");
  }
  else if(up_status==0&& down_status==0&& left_status==0&&right_status==0){
    digitalWrite(wiel2, LOW);
    digitalWrite(wiel4, LOW);
    lcd.clear();
  }
  if(right_status){
    
    Serial.println("Right");
    digitalWrite(wiel1, HIGH);
    digitalWrite(wiel3, HIGH);
    analogWrite(wiel1,duty_waarde);
    analogWrite(wiel3,duty_waarde);
    lcd.setCursor(0,0);
    lcd.print("Rechts");
  }
   else if(up_status==0&& down_status==0&& left_status==0&&right_status==0){
    digitalWrite(wiel1, LOW);
    digitalWrite(wiel3, LOW);
    lcd.clear();
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}