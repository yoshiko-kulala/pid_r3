#ifndef motor_h
#define motor_h
#include <Arduino.h>

class Motor
{
  public:
    Motor();
    void init(int a, int b,int t); //コンストラクタ、モータのピン設定
    void SetSpd(int spd);//モータの逆転設定
  private:
    int a_pin;//ピン設定
    int b_pin;//ピン設定
    int timer;
};

#endif
