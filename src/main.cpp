/*
面向对象的点灯程序
by chenzy
*/
#include <Arduino.h>
#include "LED.h"

void task(void *pt){
  Led led = *(Led *)pt;

  while(1){
    led.toggle();
    vTaskDelay(led.getDelayTime());//实际上传给函数的是tick的数量
  }
}

Led led1(32,2000,"NO1");
Led led2(33,1000,"NO2");
Led led3(25,500,"NO3");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(task,"NO 1",1024*6,&led1,1,NULL);
  xTaskCreate(task,"NO 2",1024*6,&led2,1,NULL);
  xTaskCreate(task,"NO 3",1024*6,&led3,1,NULL);

 }

void loop() {
}