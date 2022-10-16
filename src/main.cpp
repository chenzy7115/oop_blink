/*
面向对象的点灯程序
by chenzy
*/
#include <Arduino.h>
#include "LED.h"

//使用封装了task的类必须在全局中创建
Led led1(32,2000,"NO1");
Led led2(33,1000,"NO2");
Led led3(25,500,"NO3");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(23,INPUT_PULLUP);

  Serial.println("开启任务");
  led1.openLed();
  led2.openLed();
  led3.openLed();
}

void loop() {
  if(digitalRead(23)==LOW){
    Serial.println("删除任务");
    led1.closeLed();
    led2.closeLed();
    led3.closeLed();
    delay(1000);
  }
}