#include <Time.h>
#include <TimeLib.h>

int contador_dia = 0;
int dias_apagado[4] = {1, 2, 3, 9};
int dias_apagado_array_length = 4;
int timbre = 3;
unsigned long tiempo = 0;
int tiempo_inicio = millis();

//tiempo de las horas de clases
unsigned long tiempo_1ra_hora = 20000;
unsigned long tiempo_2da_hora = 50000;
unsigned long tiempo_era_hora = 80000;
unsigned long recreo_1 = 110000;
unsigned long tiempo_4ta_hora = 130000;
unsigned long tiempo_5ta_hora = 160000;
unsigned long tiempo_6ta_hora = 190000;
unsigned long recreo2 = 215000;
unsigned long tiempo_7ma_hora = 255000;
unsigned long tiempo_8va_hora = 285000;
unsigned long tiempo_salir = 315000;

//fUNCION SETUP
void setup()
{
   Serial.begin(9600);
   pinMode(3, OUTPUT);
   setTime(07, 04, 37, 14, 02, 2020);
}

//FUNCION PRINTTIME PARA LIBERAR LA FUNCION LOOP
void printTime(time_t t)
{
   Serial.print(day(t));
   Serial.print(+"/");
   Serial.print(month(t));
   Serial.print(+"/");
   Serial.print(year(t));
   Serial.print(" ");
   Serial.print(hour(t));
   Serial.print(+":");
   Serial.print(minute(t));
   Serial.print(":");
   Serial.println(second(t));
   delay(1000);
   // Serial contador Dias inicia en 0
   Serial.print("dia: ");
   Serial.println(contador_dia);
}

//FUNCION LOOP PARTE PRINCIPAL DE TU CODIGO.

void loop()
{
   time_t t = now();
   printTime(t);

   for (int i = 0; i < dias_apagado_array_length; i++)
   {

      if (contador_dia == dias_apagado[i])
      {
         Serial.print("timbre apagado: ");
         delay(1000);
         digitalWrite(3, LOW);
         delay(25000);
      }
      else
      {

         // ciclo del timbre
         Serial.println(tiempo_1ra_hora);
         Serial.print("1ra hora : ");
         tiempo = millis();
         if (millis() > tiempo_1ra_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); // tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {
            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }
         Serial.println(tiempo_2da_hora);
         Serial.println("2da hora: ");
         tiempo = millis();
         if (millis() > tiempo_2da_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_era_hora);
         Serial.print("3era hora : ");
         tiempo = millis();
         if (millis() > tiempo_era_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(recreo_1);
         Serial.println("recreo1: ");
         tiempo = millis();
         if (millis() > recreo_1)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(15000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_4ta_hora);
         Serial.println("4ta hora: ");
         tiempo = millis();
         if (millis() > tiempo_4ta_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_5ta_hora);
         Serial.println("5ta hora: ");
         tiempo = millis();
         if (millis() > tiempo_5ta_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_6ta_hora);
         Serial.println("6ta hora: ");
         tiempo = millis();
         if (millis() > tiempo_6ta_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(20000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }
         Serial.println(recreo2);
         Serial.println("recreo 2: ");
         tiempo = millis();
         if (millis() > recreo2)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(35000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_7ma_hora);
         Serial.println("7ma hora: ");
         tiempo = millis();
         if (millis() > tiempo_7ma_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_8va_hora);
         Serial.println("8va hora: ");
         tiempo = millis();
         if (millis() > tiempo_8va_hora)
         {

            digitalWrite(3, HIGH);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led activa");
            delay(5000); //tiempo que durara encendido
            digitalWrite(3, LOW);
            delay(25000); // cada cuanto me va a prender el tiembre
         }
         else
         {

            digitalWrite(3, LOW);
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
         }

         Serial.println(tiempo_salir);
         Serial.println("tiempo salir: ");
         tiempo = millis();
         if (millis() > tiempo_salir)
         {

            digitalWrite(3, HIGH);
            delay(5000); // cada cuanto me va a prender el tiembre
            Serial.print("Ha transcurrido: ");
            Serial.print(tiempo / 1000);
            Serial.print("s: ");
            Serial.println("Led desactiva");
            delay(1000);
            digitalWrite(3, LOW);
            delay(25000); // lo de durara apagado luego de concluir el dia
            if (millis() > tiempo_salir)
            {
               contador_dia++;
               Serial.print(contador_dia++);
            }
            // hara que mi contador_dia aumente en uno cuando termine el dia
         }
      }
   }
}
