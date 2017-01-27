#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Motor_DC.h"

void Motor_DC::Inicializar_Motor()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Pwm, OUTPUT);
}
void Motor_DC::Atras(int Velocidad)
{
  analogWrite(Pwm,Velocidad );
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
}
void Motor_DC::Adelante(int Velocidad)
{
  analogWrite(Pwm,Velocidad );
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
}
void Motor_DC::Stop()
{
  analogWrite(0, Pwm);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
}
