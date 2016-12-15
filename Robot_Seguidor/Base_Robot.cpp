#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Base_Robot.h"

void Base_Robot::Inicializar_Robot()
{
  Motor_1.Inicializar_Motor();
  Motor_2.Inicializar_Motor();
}

void Base_Robot::Atras(int Velocidad_1,int Velocidad_2)
{
  Motor_1.Atras(Velocidad_1);
  Motor_2.Atras(Velocidad_2);
}
void Base_Robot::Adelante(int Velocidad_1,int Velocidad_2)
{
  Motor_1.Adelante(Velocidad_1);
  Motor_2.Adelante(Velocidad_2);
}
void Base_Robot::Stop()
{
  Motor_1.Stop();
  Motor_2.Stop();
}
