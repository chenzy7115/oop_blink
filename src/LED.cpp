#include "LED.h"

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