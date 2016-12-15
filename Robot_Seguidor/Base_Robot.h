#include "Motor_DC.h"
class Base_Robot
{  
  private:
  
  
  public:
  Motor_DC Motor_1;
  Motor_DC Motor_2;
  Base_Robot(int Pin_Motor_1A,int Pin_Motor_1B,int PWM_1, int Pin_Motor_1C, int Pin_Motor_1D,int PWM_2): Motor_1(Pin_Motor_1A,Pin_Motor_1B,PWM_1), Motor_2(Pin_Motor_1C,Pin_Motor_1D,PWM_2){}
  void Inicializar_Robot();
  void Adelante(int Velocidad_1,int Velocidad_2);
  void Atras(int Velocidad_1,int Velocidad_2);
  void Stop();
};
