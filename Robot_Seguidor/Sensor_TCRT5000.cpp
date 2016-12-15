#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Sensor_TCRT5000.h"

void Sensor::Inicializar()
{
  pinMode(Pin_sensor, INPUT);
}

int Sensor::Leer_sensor()
{
  return digitalRead(Pin_sensor);
}