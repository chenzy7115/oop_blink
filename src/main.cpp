/*
面向对象的电灯程序
by chenzy
*/
#include <Arduino.h>
#include "LED.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // led1.setPin(32);
  // led2.setPin(33);
  // led3.setPin(25);

  Led led1(32,"1"),led2(33,"2"),led3(25,"3");

  led1.on();
  led2.on();
  led3.on();
  delay(1000);

  led1.off();
  led2.off();
  led3.off();
  delay(1000);
  
 }

void loop() {
  // put your main code here, to run repeatedly:
  // led1.toggle();
  // led2.toggle();
  // led3.toggle();
  // Serial.print(sizeof(led1));//统计对象实际占用的byte数
  // Serial.println(" Bytes");
  // delay(100);
}