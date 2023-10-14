#define BLYNK_TEMPLATE_ID "TMPL3-g7mI7aq"
#define BLYNK_TEMPLATE_NAME "DHT22"
#define BLYNK_AUTH_TOKEN "VemUz_kpbf8OkS5wQtj5zwdJycGV16-w"
#define BLYNK_PRINT Serial
#define DHT_PIN 21  
#define DHT_TYPE DHT22
#define LED 15   

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Stepper.h>

DHT dht(DHT_PIN, DHT_TYPE);
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 33, 25, 26, 27);

char ssid[] = "Wokwi-GUEST";
char pass[] = "";
int mode=0;
int led=0;
int motor=0;

void setup()
{
  Serial.begin(115200);
  myStepper.setSpeed(100000);
  pinMode(LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
}
 
void loop()
{ 

  Blynk.run();
 
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();

  if (!isnan(humidity) && !isnan(temperature)) {

        Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
}

if(mode==0){

   if(temperature>35 || temperature<12 || humidity>70 || humidity<40){

     myStepper.step(50);
     digitalWrite(LED, HIGH);
   }else{ 
    digitalWrite(LED, LOW);
    }
}else{

 if(led==1) {digitalWrite(LED, HIGH);}else{digitalWrite(LED, LOW);}
 if(motor==1){myStepper.step(50);}

}

// myStepper.step(100);
// Serial.println("");
// Serial.print(mode);
// Serial.print(led);
// Serial.print(motor);
// Serial.println("");

}



BLYNK_WRITE(V4)
{
  mode = param.asInt(); 
}

BLYNK_WRITE(V2)
{
  led = param.asInt();
}

BLYNK_WRITE(V3)
{
  motor = param.asInt(); 
}
