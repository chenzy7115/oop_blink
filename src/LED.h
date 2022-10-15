#ifndef LED_H
#define LED_H
#include <Arduino.h>

//定义LED类
//_pin定义管脚,setPin()设置管脚号
//getPin()获得管脚号
//on()管脚为高电平
//off（）管脚为低电平
//toggle()高低电平交替
class Led{
  private://self and friend
   byte _pin;

  public:
    void setPin(byte pin_param);
    byte getPin() const;
    void on() const;
    void off() const;
    void toggle() const;
};

#endif