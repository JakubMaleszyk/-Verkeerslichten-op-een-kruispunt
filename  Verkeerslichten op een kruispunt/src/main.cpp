#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
int rode_led=A1;
int gele_led=A2;
int groene_led=A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(rode_led, OUTPUT);
  pinMode(gele_led, OUTPUT);
  pinMode(groene_led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rode_led, HIGH);
  digitalWrite(gele_led, LOW);
  delay(10000);
  digitalWrite(rode_led, LOW);
  digitalWrite(groene_led,HIGH);
  delay(8000);
  digitalWrite(groene_led, LOW);
  digitalWrite(gele_led,HIGH);
  delay(2000);
  }

// put function definitions here:
