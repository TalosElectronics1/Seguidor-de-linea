#include "Base_Robot.h"
#include "Sensor_TCRT5000.h"
class Robot_Seguidor
{
private:
	Base_Robot Robot;
	Sensor Sensor_1;
  	Sensor Sensor_2;
  	Sensor Sensor_3;
  	Sensor Sensor_4;
  	Sensor Sensor_5;
  	Sensor Sensor_6;
  	int sensor[6];
  	float Error=0, P=0, I=0, D=0, PID=0;
  	float Error_Anterior=0, Anteriror_I=0;

public:
	Robot_Seguidor(int Pin_Motor_1A,
					int Pin_Motor_1B,
					int PWM_1, 
					int Pin_Motor_1C, 
					int Pin_Motor_1D,
					int PWM_2,
					int PinS1,
					int PinS2,
					int PinS3,
					int PinS4,
					int PinS5,
					int PinS6)
	:Robot(Pin_Motor_1A, Pin_Motor_1B, PWM_1, Pin_Motor_1C, Pin_Motor_1D, PWM_2),Sensor_1(PinS1),Sensor_2(PinS2),Sensor_3(PinS3),Sensor_4(PinS4),Sensor_5(PinS5),Sensor_6(PinS6){}
	void Inicializar();
	void Lectura_de_sensores();
	void Modo_Seguidor(int kP,int KI,int KD,int Velocidad);
};	