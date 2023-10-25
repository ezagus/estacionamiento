
const int Trigger = 8;   //Pin digital 2 para el Trigger del sensor
const int Echo = 9;   //Pin digital 3 para el Echo del sensor
const int Trigger2 = 3;   //Pin digital  para el Trigger del sensor
const int Echo2 = 2;   //Pin digital 3 para el Echo del sensor
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(Trigger2, OUTPUT); //pin como salida
  pinMode(Echo2, INPUT);  //pin como entrada
  digitalWrite(Trigger2, LOW);//Inicializamos el pin con 0
}

void loop()
{
  long t2;
  long d2;
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(Trigger2, HIGH);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  digitalWrite(Trigger2,LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  t2 = pulseIn(Echo2, HIGH);
  d2 = t2/59;
  Serial.println(d);
;

}
