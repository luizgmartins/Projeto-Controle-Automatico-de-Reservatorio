/*  Projeto de Estágio - Controle de reservatório de água
 *   Author: Luiz Gabriel Martins
 *   Instituto Federal de Alagoas - IFAL (2019)
*/

#include <DS1307.h>
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

#define BLYNK_PRINT Serial
SoftwareSerial SwSerial(10, 2); // RX, TX
char auth[] = "daf6b3f526ec41e1b4c84bac89f8ea17";
SoftwareSerial SerialBLE(10, 2); // RX, TX

#define gatilho 9
#define echo 8
float tempo;
float distancia_cm;
float teste; 
int final; //Variável final do sensor de fluxo
float vazao; //Variável para armazenar o valor em L/min
int contaPulso; //Variável para a quantidade de pulsos
float Litros = 0; //Variável para Quantidade de agua
float MiliLitros = 0; //Variavel para Conversão
int sleep0;
int sleep1;
String sleep2;
String sleep3;
int sleep4;
int relogio_0;
int relogio_1;
int relogio_2;
DS1307 rtc(A4, A5);
String hora;
String dia;
BlynkTimer timer;
int i;

void sendSensor()
{ 
  cli(); //Desabilita interrupção
  hora = rtc.getTimeStr();
  Serial.println(hora);
  dia = rtc.getDOWStr(FORMAT_SHORT);
  Serial.println(dia);
  if(relogio_1 == 1)
  { 
    if(dia == "Monday" || dia == "Tuesday" || dia == "Wednesday" || dia == "Thursday" || dia == "Friday")
      {
       if(hora == "08:00:00")
        {
          digitalWrite(5, HIGH);
        }
       else if(hora == "16:00:00")
        {
          digitalWrite(5, LOW);   //liga o fluxo de agua
        }
      }
   } 
   else if(relogio_2 == 1)
      { 
        if(dia == "Monday" || dia == "Tuesday" || dia == "Wednesday" || dia == "Thursday" || dia == "Friday" || dia == "Saturday")
          {
              if(hora == sleep2)
                 {
                   digitalWrite(5, HIGH);
                 }
              else if(hora == sleep3 )
                 {
                   digitalWrite(5, LOW);  //liga o fluxo de agua
                 }
          }
       } 
  digitalWrite(gatilho, HIGH);
  delayMicroseconds(10);
  digitalWrite(gatilho, LOW);
  tempo = pulseIn(echo, HIGH);
  distancia_cm = (tempo / 29.4) / 2;
  final = ((distancia_cm - 4.02) * 100) / 12;
  final = 100 - final;
  if ( final <= 100 || final >= 0 ) 
      {
          Serial.print("Valor: ");
          Serial.print(distancia_cm);
          Serial.print(" cm    ");
          Serial.print(final);
          Serial.println(" %");
          teste = distancia_cm;
       }
  if (final <= 35)
       {
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
       }
  if (final >= 100)
        {
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(4, HIGH);
        }
   if(hora=="00:00:00")
   { Litros = 0;
    }
    if(hora=="00:00:01")
   { Litros = 0;
    }
   vazao = contaPulso / 5.1; //Converte para L/min
   Serial.print(vazao); //Escreve no display o valor da vazão
   Serial.print(" L/min "); //Escreve L/min
   MiliLitros = vazao / 60;
   Litros = Litros + MiliLitros;
   float ml = Litros*1000.0;
   Serial.print(Litros);
   Serial.print("L ");
   Serial.print(ml);
   Serial.println(" mL ");
   contaPulso = 0;//Zera a variável
   sei(); //Habilita interrupção*/
   Blynk.virtualWrite (V5, final);
   Blynk.virtualWrite(V6, Litros);
   Serial.println(" teste ");
   //Blynk.virtualWrite(V8, hora);
   
}

   BLYNK_WRITE(V0)
      {   
        sleep0 = param.asInt();
        Serial.println(sleep0);
        sleep_0();
      }
void sleep_0 ()
{
    if(sleep0 == 1)
      {
        relogio_0 = 1;
        relogio_1 = 0;
        relogio_2 = 0;
      }
}
BLYNK_WRITE(V1)
{   
     sleep1 = param.asInt();
     Serial.println(sleep1);
     if(sleep1 == 1)
        {sleep_1();}
}
void sleep_1 ()
{
     if(sleep1 == 1)
     {
        relogio_0 = 0;
        relogio_1 = 1;
        relogio_2 = 0;
     }
}
BLYNK_WRITE(V3)
{   
      sleep2 = param.asStr();
      Serial.println(sleep2);
}
BLYNK_WRITE(V4)
{   
      sleep3 = param.asStr();
      Serial.println(sleep3);
}
BLYNK_WRITE(V2)
{   
      sleep4 = param.asInt();
      Serial.println(sleep4);
      if(sleep4 == 1)
          {sleep_4();}
}
void sleep_4 ()
{
      if(sleep4 == 1)
      {
          relogio_0 = 0;
          relogio_1 = 0;
          relogio_2 = 1;
      }
}
void incpulso ()
{
       contaPulso++; //Incrementa a variável de pulsos
}
void setup()
{
  Serial.begin(9600);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  pinMode(gatilho, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  rtc.halt(false);
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
  attachInterrupt(digitalPinToInterrupt(3), incpulso, RISING);
  relogio_0 = 2;
  relogio_1 = 0;
  relogio_2 = 0;
  Serial.println("Aguardando conexão...");
  timer.setInterval(1000L, sendSensor);
}
void loop()
{
  Blynk.run();
  timer.run();
}
