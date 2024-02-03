//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
int pessoas = 0;
long tempo;
int h,m,s;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  tempo = millis();
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
 if(cmMsec < 30)
 {
  h = millis()/3600000;
  m = h%3600000;
  s = millis()/1000;
  pessoas++;
  Serial.print("Pessoas que entraram na loja: ");
  Serial.print(pessoas);
  Serial.print(" Registro de entrada: ");
  Serial.print(h);
  Serial.print("h");
  Serial.print(":");
  Serial.print(m);
  Serial.print("m");
  Serial.print(":");
  Serial.print(s);
  Serial.print("s");
  Serial.println(" ");
  }
  while(cmMsec<30)
  {
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  }
 delay(500);
  }
  //Exibe informacoes no serial monitor
  /*Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  */


