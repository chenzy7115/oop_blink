#include "LED.h"

Led::~Led(){}

Led::Led(){
  _pin = 2;
  _color = "UNKOWN";
}

Led::Led(byte pin_parm,int delayTime,String color_param) : _delayTime(delayTime),_color(color_param){
  setPin(pin_parm);
}

void Led::setPin(byte pin_param){

  if ((pin_param < 40) && (pin_param >= 0))
  {
    _pin = pin_param;
    pinMode(_pin, OUTPUT);
  }
  else
  {
    _pin = 2;
    Serial.println("invalid pin number, use default pin 2 instead");
  }
}


byte Led::getPin() const{
  return _pin;
}

void Led::on() const{
  digitalWrite(_pin,HIGH);
}

void Led::off() const{
  digitalWrite(_pin,LOW);
}

void Led::toggle() const{
  digitalWrite(_pin,!digitalRead(_pin));
}

void Led::task(){
  while (1)
  {
    this->toggle();
    vTaskDelay(this->_delayTime);
  }
}

  //下面的函数封装任务到类中的关键函数
  void Led::startTaskImpl(void* _this) {
  static_cast<Led*>(_this)->task();
}

  void Led::openLed(){
  xTaskCreate(this->startTaskImpl,"Task",2048,this,5,&_taskHandle);
}

  void Led::closeLed(){
  this->on();
  vTaskDelete(_taskHandle);
}
