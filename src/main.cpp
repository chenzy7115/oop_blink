/*
面向对象的电灯程序
by chenzy
*/
#include <Arduino.h>
#include "LED.h"



Led ledred;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ledred.setPin(32);

  ledred.on();
  delay(1000);

  ledred.off();
  delay(1000);



}

void loop() {
  // put your main code here, to run repeatedly:
  ledred.toggle();
  Serial.print(sizeof(ledred));//统计对象实际占用的byte数
  Serial.println(" Bytes");
  delay(100);
}