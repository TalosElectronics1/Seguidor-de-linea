
class Sensor
{
  private:
  int Pin_sensor;

  public:
  Sensor(int pin): Pin_sensor(pin){}//Constructor
  void Inicializar(); 
  int Leer_sensor();
};
