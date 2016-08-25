//Ganancias para el PID
float Kp=15,Ki=5,Kd=12;
float Error=0, P=0, I=0, D=0, PID=0;
float Error_Anterior=0, Anteriror_I=0;
int sensor[6]={0, 0, 0, 0, 0, 0};

int Velocidad=125;

void Lectura_de_sensores(void);
void Calculo_PID(void);
void Adelante(void);
void Alto(void);

int s1=2, s2=3, s3=4, s4=5, s5=6, s6=7;

void setup()
{
 pinMode(s1,INPUT); 
 pinMode(s2,INPUT); 
 pinMode(s3,INPUT); 
 pinMode(s4,INPUT);
 pinMode(s5,INPUT);  
 pinMode(s6,INPUT);  



 pinMode(11,OUTPUT); //PWM motor Izquierdo
 pinMode(13,OUTPUT); //Left Motor Izquierda
 pinMode(12,OUTPUT); //Right Motor Izquierdo

 pinMode(9,OUTPUT); //PWM motor Derecho
 pinMode(8,OUTPUT); //Left Motor Derecho
 pinMode(10,OUTPUT);  //Right Motor Derecho

 
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
    Lectura_de_sensores();
    Calculo_PID();
    Adelante();
}

void Lectura_de_sensores()
{
  sensor[0]=!digitalRead(s1);
  sensor[1]=!digitalRead(s2);
  sensor[2]=!digitalRead(s3);
  sensor[3]=!digitalRead(s4);
  sensor[4]=!digitalRead(s5);
  sensor[5]=digitalRead(s6);
  if(sensor[5]==1)
  {
    Alto();
  }else{
  
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
  else 
  if(Error==-4) 
  Error=-5;
  else 
  Error=5;
  }
}

void Calculo_PID()
{
    P = Error;
    I = I + Anteriror_I;
    D = Error-Error_Anterior;
    
    PID = (Kp*P) + (Ki*I) + (Kd*D);
    
    Anteriror_I=I;
    Error_Anterior=Error;
}

void Adelante()
{
    // Calculating the effective motor speed:
    int Velocidad_motor_izquierdo = Velocidad-PID;
    int Velocidad_motor_derecho = Velocidad+PID;

    
    constrain(Velocidad_motor_izquierdo,0,200);
    constrain(Velocidad_motor_derecho,0,200);


    analogWrite(11,Velocidad-PID);   //Velocidad del motor izquierdo
    analogWrite(9,Velocidad+PID);  //Velocidad del motor derecho
  
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);

}
void Alto()
{
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);

}

