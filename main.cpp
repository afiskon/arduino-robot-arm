#include <Arduino.h>
#include "Servo.h"

#define DELAY_MS 20

Servo s1;
Servo s2;
Servo s3;
Servo s4;

int last_report = 0;
int loop_counter = 0;

void setup()
{
  Serial.begin(9600);

  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
}

void loop()
{
  int p1val = analogRead(A0);
  int p2val = analogRead(A1);
  int p3val = analogRead(A2);
  int p4val = analogRead(A3);

  loop_counter++;

  if(loop_counter >= 1000 / DELAY_MS)
  {
    Serial.println("p1val = " + String(p1val) + " (raw angle: " + String(map(p1val, 0, 1023, 0, 180)) + ")");
    Serial.println("p2val = " + String(p2val) + " (raw angle: " + String(map(p2val, 0, 1023, 0, 180)) + ")");
    Serial.println("p3val = " + String(p3val) + " (raw angle: " + String(map(p3val, 0, 1023, 0, 180)) + ")");
    Serial.println("p4val = " + String(p4val) + " (raw angle: " + String(map(p4val, 0, 1023, 0, 180)) + ")");
    Serial.println("");
    loop_counter = 0;
  }

  s1.write(map(p1val, 0, 1023,  0, 179));
  s2.write(map(p2val, 0, 1023, 85, 179));
  s3.write(map(p3val, 0, 1023, 50, 155));
  s4.write(map(p4val, 0, 1023,  4,  23));
  delay(DELAY_MS);
}
