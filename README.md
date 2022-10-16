# oop_blink
3.将freeRTOS的task封装进class中，方便调用。具体看LED.H中的说明。

2.增加使用freeRTOS多任务方式来显示控制3个LED的亮灭，不在使用delay方式来进行延时，使用freeRTOS中的vTaskDelay()函数。
vTaskDelay()的参数tick是使用MCU的tick计数器的计数次数，在ESP32每个tick为1ms，因此1000次tick就是一秒。

1.2022-10-16 在类中增加了析构函数和构造函数


面向对象的点灯程序
芯片EPS32
开发框架arduino

by chenzy
# 已经验证通过
