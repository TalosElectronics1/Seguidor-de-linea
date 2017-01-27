#include "Robot_Seguidor.h"
#include <Arduino.h> //Permite utilizar los comandos de Arduino

void Robot_Seguidor::Inicializar()
{
	Robot.Inicializar_Robot();
	Sensor_1.Inicializar();
	Sensor_2.Inicializar();
	Sensor_3.Inicializar();
	Sensor_4.Inicializar();
	Sensor_5.Inicializar();
}
void Robot_Seguidor::Modo_Seguidor(int Kp,int Ki,int Kd,int Velocidad)
{
	Lectura_de_sensores();
	P = Error;
    I = I + Anteriror_I;
    D = Error-Error_Anterior;
    
    PID = (Kp*P) + (Ki*I) + (Kd*D);
    
    Anteriror_I=I;
    Error_Anterior=Error;
    int Velocidad_motor_izquierdo = Velocidad-PID;
    int Velocidad_motor_derecho = Velocidad+PID;

    
    constrain(Velocidad_motor_izquierdo,0,255);
    constrain(Velocidad_motor_derecho,0,255);
    Robot.Adelante(Velocidad_motor_izquierdo,Velocidad_motor_derecho);

}
void Robot_Seguidor::Lectura_de_sensores()
{
  
  sensor[0]=Sensor_1.Leer_sensor();
  sensor[1]=Sensor_2.Leer_sensor();
  sensor[2]=Sensor_3.Leer_sensor();
  sensor[3]=Sensor_4.Leer_sensor();
  sensor[4]=Sensor_5.Leer_sensor();
  
  //Detectar la desviacion ("Error") del seguidor de linea
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  {
   Error=Error;
  }
  else
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1))
  Error=4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
  Error=3;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==0))
  Error=2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))
  Error=1;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
  Error=0;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
  Error=-1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  Error=-2;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  Error=-3;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  Error=-4;
 
}

