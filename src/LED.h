/* 
   参考文献:
   https://www.freertos.org/FreeRTOS_Support_Forum_Archive/July_2010/freertos_Is_it_possible_create_freertos_task_in_c_3778071.html
   https://stackoverflow.com/questions/45831114/c-freertos-task-invalid-use-of-non-static-member-function
   https://electronics.stackexchange.com/questions/373793/using-c-objects-within-freertos-tasks
*/
#ifndef LED_H
#define LED_H
#include <Arduino.h>

//关键：使用该类时创建实体对象的时候一定要在全局创建
//定义LED类
//_pin定义管脚,setPin()设置管脚号
//getPin()获得管脚号
//getDelayTime()获得延时值
//on()管脚为高电平
//off（）管脚为低电平
//toggle()高低电平交替
//task();//在结构体中封装任务函数时所所使用的任务函数
//关键：startTaskImpl();//用于显性的转换task()类型，这是封装任务函数的关键
//openLed();//供用户使用封装好的开启led的函数
//closeLed();//供用户使用封装好的关闭led的函数
class Led{
  private://self and friend
   byte _pin;
   String _color;
   int _delayTime;
   TaskHandle_t _taskHandle;
   //TaskHandle_t这个句柄其实就是任务的任务堆栈
   
  public:
    Led();//默认的constructor(构造函数)
    Led(byte pin_parm,int delay_Time = 1000,String color_param="UNKOWN");//重载构造函数（overload constructor)
    ~Led();//析构函数(destructor)
    
    void setPin(byte pin_param);//设置管脚
    byte getPin() const;//获得管脚值
    int getDelayTime() const {return _delayTime;};//获得延时值
    //iint getDelayTime()书写中使用了inline function方式
    //一般不推荐在头文件中使用，原则上头文件只定义函数，而不实现方法
    void on() const;//高电平
    void off() const;//低电平
    void toggle() const;//高低电平交替变化

    void task();//在结构体中封装任务函数时所所使用的任务函数
    static void startTaskImpl(void*);//用于显性的转换task()类型，这是封装任务函数的关键
    //xTaskCreate不能直接调用task()而是要调用转换后的函数
    //使用了static_cast<>运算符来进行显性类型转换
    //具体说明看https://blog.csdn.net/weixin_41036447/article/details/115984885
    void openLed();//供用户使用封装好的开启led的函数
    void closeLed();//供用户使用封装好的关闭led的函数

};

#endif