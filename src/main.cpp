/*
面向对象的电灯程序
by chenzy
*/
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