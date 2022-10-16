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
   String _color;
   
  public:
    Led();//默认的constructor(构造函数)
    Led(byte pin_parm,String color_param="UNKOWN");//重载构造函数（overload constructor)
    ~Led();//析构函数(destructor)
    
    void setPin(byte pin_param);//设置管脚
    byte getPin() const;//获得管脚值
    void on() const;//高电平
    void off() const;//低电平
    void toggle() const;//高低电平交替变化
};

#endif