
class Motor_DC
{
  private:
  int A;
  int B;
  int Pwm;
 
  public:
  Motor_DC(int a,int b,int pwm): A(a), B(b),Pwm(pwm){}//Constructor
  void Inicializar_Motor();
  void Adelante(int Velocidad);
  void Atras(int Velocidad);
  void Stop();
};
