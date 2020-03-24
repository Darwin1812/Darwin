#include <Time.h>
#include <TimeLib.h>

//dias apagado esta colocado en orden inverso
int dias_apagado[4] = {9, 3, 2, 1};

int dias_apagado_array_length = 4;
int DIAS_YEAR = 365;
int timbre = 3;
unsigned long tiempo = 0;
int tiempo_inicio = millis();

//Se repiten mucho pueden ser constantes
int DELAY_PRINT = 5000;
int DELAY_LOW = 25000;
int DELAY_LOW_RECREO1 = 15000;
int DELAY_LOW_SEXTA_HORA = 20000;
int DELAY_LOW_RECREO2 = 35000;

//Deberias tener un delay para un dia completo apagado
int DELAY_ALL_DAY = 250000;

//tiempo de las horas de clases
unsigned long tiempo_1ra_hora = 20000;
unsigned long tiempo_2da_hora = 50000;
unsigned long tiempo_3ra_hora = 80000;
unsigned long recreo_1 = 110000;
unsigned long tiempo_4ta_hora = 130000;
unsigned long tiempo_5ta_hora = 160000;
unsigned long tiempo_6ta_hora = 190000;
unsigned long recreo_2 = 215000;
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
void printTime(time_t t, int contador_dia)
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

//FUNCION TIMBRE APAGADO
void timbreApagado(int message, int pin, int delay_print, int delay_low)
{
   Serial.print(message);
   delay(delay_print);
   digitalWrite(pin, LOW);
   delay(delay_low);
}

//FUNCION TIMBRE ENCENDIDO
void timbreEncendido(int message, int pin, int tiempo)
{
   digitalWrite(pin, HIGH);
   Serial.print(message);
   Serial.print(tiempo / 1000);
   Serial.print("s: ");
}

//FUNCION TIEMBRE ENTRE HORAS DE CLASE
void timbreEntreHoras(int pin, int tiempo)
{
   digitalWrite(pin, LOW);
   Serial.print("Ha transcurrido: ");
   Serial.print(tiempo / 1000);
   Serial.print("s: ");
   Serial.println("Led desactiva");
   delay(1000);
}

//TIEMBRE POR HORAS

void timbreNormal(int message, int pin, int tiempo_hora, int delay_print, int delay_low)
{
   Serial.println(tiempo_hora);
   Serial.print(message);
   int tiempo = millis();

   if (millis() > tiempo_hora)
   {
      timbreEncendido("Ha transcurrido: ", pin, tiempo);
      //NOTA: Revisar logica este apagado deberia ser por menos tiempo
      timbreApagado("Led activa", pin, delay_print, delay_low);
   }
   else
   {
      timbreEntreHoras(pin, tiempo);
   }
}

//TIEMPO SALIR
void timpoSalida(int message, int pin, int tiempo_hora, int delay_print, int delay_low, int contador_dia)
{
   //NOTA: REVISAR BIEN ESTA LOGICA DE TIEMPO DE SALIDA
   Serial.println(tiempo_hora);
   Serial.print(message);
   int tiempo = millis();
   if (millis() > tiempo_hora)
   {

      digitalWrite(pin, HIGH);
      delay(delay_print); // cada cuanto me va a prender el tiembre
      Serial.print("Ha transcurrido: ");
      Serial.print(tiempo / 1000);
      Serial.print("s: ");
      Serial.println("Led desactiva");
      delay(1000);
      digitalWrite(pin, LOW);
      delay(delay_low); // lo de durara apagado luego de concluir el dia

      //NOTA: NO ENTIENDO PORQUE VOLVER A PREGUNTAR ESTO DENTRO DE ESTE IF
      Serial.print("IMPRIME EL DIA FINALIZADO DE 0 A 365: ");
      Serial.print(contador_dia);

      // hara que mi contador_dia aumente en uno cuando termine el dia
   }
}

//CICLO DE UN DIA COMPLETO
void diaCompleto(int i)
{
   /*** CICLO TIMBRE NORMAL DIA DE CLASES ****/

   //TIMBRE PRIMERA HORA
   timbreNormal("1ra hora : ", timbre, tiempo_1ra_hora, DELAY_PRINT, DELAY_LOW);

   //TIMBRE SEGUNDA HORA
   timbreNormal("2da hora : ", timbre, tiempo_2da_hora, DELAY_PRINT, DELAY_LOW);

   //TIMBRE TERCERA HORA
   timbreNormal("3ra hora : ", timbre, tiempo_3ra_hora, DELAY_PRINT, DELAY_LOW);

   //RECREO 1
   timbreNormal("Recreo 1:  ", timbre, recreo_1, DELAY_PRINT, DELAY_LOW_RECREO1);

   //TIMBRE CUARTA HORA
   timbreNormal("4ra hora : ", timbre, tiempo_4ta_hora, DELAY_PRINT, DELAY_LOW);

   //TIMBRE QUINTA HORA
   timbreNormal("5ta hora : ", timbre, tiempo_5ta_hora, DELAY_PRINT, DELAY_LOW);

   //TIMBRE SEXTA HORA
   timbreNormal("6ta hora : ", timbre, tiempo_6ta_hora, DELAY_PRINT, DELAY_LOW_SEXTA_HORA);

   //TIMBRE RECREO 2
   timbreNormal("Recreo 2 : ", timbre, recreo_2, DELAY_PRINT, DELAY_LOW_RECREO2);

   //TIMBRE SEPTIMA HORA
   timbreNormal("7ma hora : ", timbre, tiempo_7ma_hora, DELAY_PRINT, DELAY_LOW);

   //TIMBRE OCTAVA HORA
   timbreNormal("8va hora : ", timbre, tiempo_8va_hora, DELAY_PRINT, DELAY_LOW);

   // TIEMPO SALIDA, i LLEVA EL CONTEO DE LOS DIAS Y
   //SE INCREMENTA EN EL FOR

   tiempoSalida("Tiempo Salida : ", timbre, tiempo_salir, DELAY_PRINT, DELAY_LOW, i);
}

//FUNCION LOOP PARTE PRINCIPAL DEL CODIGO.

void loop()
{

   //NOTA: Cambie la logica del for.
   /*
      Uso la variable DIAS_YEAR para los 365 dias del año.
      El contador i lleva los dias que van pasando.
      (i hace la misma funcion de contador dias)

      Estudiar arreglos distinguir que es un indice y que es el valor
   */

   // el array dias apagados tiene 4 dias, y sus indices van de 0-3
   // el -1 es para no sobre pasar el indice
   // este contador se reinica con cada finalizacion del ciclo
   // a los 365 dias cumplidos

   int dias_apagados_count = dias_apagado_array_length - 1;

   for (int i = 0; i < DIAS_YEAR; i++)
   {
      time_t t = now();
      printTime(t, i);
      // cada vez que se cumpla la condicion se reduce el indice
      // dias_apagados_count es un indice
      // para dias apagados por esto el sentido inverso

      if (dias_apagados_count >= 0 && i == dias_apagado[dias_apagados_count])
      {
         //NOTA: deberia apagar por todo el dia! revisar logica
         //Cambiar el valor de DELAY_ALL_DAY al incio
         timbreApagado("Timbre apagado:", timbre, DELAY_PRINT, DELAY_ALL_DAY);

         // voy reduciendo el indice del arreglo de 3 a -1
         --dias_apagados_count;
      }
      else
      {
         /*DIA COMPLETO DE TRABAJO i REPRESENTA EL DIA EN CUESTION*/
         diaCompleto(i);
      } //FINALIZO EL IF - ELSE

   } //FINALIZO EL FOR POR DIAS
}
