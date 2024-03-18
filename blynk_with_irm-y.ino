#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID           "TMPLn9OzWtWf"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "sgFWA7EufJD05ImKB-D8L4d0EyKG0yrm"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

char ssid[] = "-----------";
char pass[] = "-----------";

#define IR_RECV_PIN D3
#define wifiLed     D4
#define buzz        3
#define light1      D5
#define light2      D7
#define light3      D1
#define light4      D8
#define light5      D2
#define fan         D0

int  Slider_Value = 0;
bool wifiFlag = 0;
bool alllight = 0;
bool light = 0;
bool nightlight = 0;
bool conlight = 0;
bool con2light = 0;
bool galllight = 0;
bool Value = 0;
bool a = 0;
bool b = 0;
bool c = 0;
bool d = 0;
bool e = 0;

IRrecv irrecv(IR_RECV_PIN);
decode_results results;

BlynkTimer timer;

/*BLYNK_WRITE(V0)
{
 Slider_Value = param.asInt();
 Blynk.virtualWrite(V0, Slider_Value);
 BUZZ();
}

void Fanspeedup()
{
 Slider_Value = Slider_Value + 10; 
 Blynk.virtualWrite(V0, Slider_Value); 
 BUZZ();
}

void Fanspeeddown()
{
 Slider_Value = Slider_Value - 10; 
 Blynk.virtualWrite(V0, Slider_Value); 
 BUZZ();
}*/

BLYNK_WRITE(V5)
{
 Value = param.asInt();
 digitalWrite(fan, Value );
 Blynk.virtualWrite(V5, Value);   
 BUZZ();                                                                                                
}

void Fanonoff()
{
 Value = !Value;
 digitalWrite(fan, Value );
 Blynk.virtualWrite(V5, Value);
 BUZZ(); 
}

BLYNK_WRITE(V1)
{ 
 light = param.asInt();
 a = light;
 digitalWrite(light1, light );
 Blynk.virtualWrite(V1, light);
 BUZZ();
}

void Light1()
{
 light = !light;
 a = light;
 digitalWrite(light1, light);
 Blynk.virtualWrite(V1, light);
 BUZZ();
}

BLYNK_WRITE(V2)
{
 nightlight = param.asInt();
 b = nightlight;
 digitalWrite(light2, nightlight);
 Blynk.virtualWrite(V2, nightlight);
 BUZZ();
}

void Light2()
{
 nightlight = !nightlight;
 b = nightlight;
 digitalWrite(light2, nightlight);
 Blynk.virtualWrite(V2, nightlight);
 BUZZ();
}

BLYNK_WRITE(V3)
{
 conlight = param.asInt();
 c = conlight;
 digitalWrite(light3, conlight);
 Blynk.virtualWrite(V3, conlight);
 BUZZ();
}

void Light3()
{ 
 conlight = !conlight;
 c = conlight;
 digitalWrite(light3, conlight);
 Blynk.virtualWrite(V3, conlight);   
 BUZZ();
}

BLYNK_WRITE(V4)
{
 con2light = param.asInt();
 d = con2light;
 digitalWrite(light4, con2light);
 Blynk.virtualWrite(V4, con2light);
 BUZZ();
}

void Light4()
{
 con2light = !con2light;
 d = con2light;
 digitalWrite(light4, con2light );
 Blynk.virtualWrite(V4, con2light);
 BUZZ();
}  

BLYNK_WRITE(V7)
{
 galllight = param.asInt();
 digitalWrite(light5, galllight);
 Blynk.virtualWrite(V7, galllight);
 BUZZ();
}

void Light5()
{
 galllight = !galllight;
 digitalWrite(light5, galllight);
 Blynk.virtualWrite(V7, galllight);
 BUZZ();
}

BLYNK_WRITE(V6)
{
 alllight = param.asInt();

 Blynk.virtualWrite(V6, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light1, alllight );
 Blynk.virtualWrite(V1, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light2, alllight ); 
 Blynk.virtualWrite(V2, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light3, alllight );
 Blynk.virtualWrite(V3, alllight);
 delay(100);   
 BUZZ();

 digitalWrite(light4, alllight );
 Blynk.virtualWrite(V4, alllight);
 delay(100); 
 BUZZ();

 Blynk.virtualWrite(V6, alllight);
 light = alllight;
 nightlight =alllight;
 conlight = alllight;
 con2light = alllight;
 Value = alllight;
 a = alllight;
 b = alllight;
 c = alllight;
 d = alllight;
}

void all_LightOnOff()
{
  alllight = !alllight;

 Blynk.virtualWrite(V6, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light1, alllight );
 Blynk.virtualWrite(V1, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light2, alllight ); 
 Blynk.virtualWrite(V2, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light3, alllight );
 Blynk.virtualWrite(V3, alllight);
 delay(100);   
 BUZZ();

 digitalWrite(light4, alllight );
 Blynk.virtualWrite(V4, alllight);
 delay(100); 
 BUZZ();

 Blynk.virtualWrite(V6, alllight);
 light = alllight;
 nightlight =alllight;
 conlight = alllight;
 con2light = alllight;
 Value = alllight;
 a = alllight;
 b = alllight;
 c = alllight;
 d = alllight;
}
void all_SwitchOff()
{
  
 alllight = 0;
 Slider_Value = alllight;

 Blynk.virtualWrite(V0, Slider_Value);
 Blynk.virtualWrite(V6, alllight);
 delay(100);
 BUZZ();

 digitalWrite(fan, alllight);
 Blynk.virtualWrite(V5, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light1, alllight );
 Blynk.virtualWrite(V1, alllight);
 delay(100);
 BUZZ(); 

 digitalWrite(light2, alllight );
 Blynk.virtualWrite(V2, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light3, alllight );
 Blynk.virtualWrite(V3, alllight);
 delay(100);  
 BUZZ();

 digitalWrite(light4, alllight );
 Blynk.virtualWrite(V4, alllight);
 delay(100);  
 BUZZ();

 digitalWrite(light5, alllight );
 Blynk.virtualWrite(V7, alllight);
 delay(100);  
 BUZZ();
 BUZZ();

 light = 0;
 nightlight = 0;
 conlight = 0;
 con2light = 0;
 Value = 0;
 a = 0;
 b = 0;
 c = 0;
 d = 0;

}  

void all_SwitchOn()
{
 alllight = 1;
 Value = 1;

 Blynk.virtualWrite(V6, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light1, alllight );
 Blynk.virtualWrite(V1, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light2, alllight );
 Blynk.virtualWrite(V2, alllight);
 delay(100);
 BUZZ();

 digitalWrite(light3, alllight );
 Blynk.virtualWrite(V3, alllight);
 delay(100);  
 BUZZ();

 digitalWrite(light4, alllight );
 Blynk.virtualWrite(V4, alllight);
 delay(100);  
 BUZZ();

 digitalWrite(light5, alllight );
 Blynk.virtualWrite(V7, alllight);
 delay(100);  
 BUZZ();
 BUZZ();

 light = 1;
 nightlight = 1;
 conlight = 1;
  Value = 1;
 a = 1;
 b = 1;
 c = 1;
 d = 1;
}  

void BUZZ()
{
 digitalWrite(buzz,1);
 delay(50);
 digitalWrite(buzz,0);
 delay(10);
}

void ST_V6()
{
 if(a==1)
 {
   if(b==1)
   {
     if(c==1)
     {
       if(d==1)
       {
        Blynk.virtualWrite(V6, 1);
       }
        else
       { 
        Blynk.virtualWrite(V6, 0);      
       }        
     }
     else
     { 
      Blynk.virtualWrite(V6, 0);      
     }             
   } 
    else
    { 
     Blynk.virtualWrite(V6, 0);      
    }        
 }
  else
  {
   Blynk.virtualWrite(V6, 0);            
  }
}
void WIFION()
{ 
 BUZZ();
 e==1;
 if(e==1)
 {
 Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
 
 // Setup a function to be called every second
 /*Blynk.virtualWrite(V1, light);
 Blynk.virtualWrite(V2,  nightlight);
 Blynk.virtualWrite(V3, conlight);
 Blynk.virtualWrite(V4,  con2light);
 Blynk.virtualWrite(V5,  Value);
 Blynk.virtualWrite(V6, alllight);
 Blynk.virtualWrite(V0, Slider_Value);*/
  Blynk.virtualWrite(V1,0);delay(50);
  Blynk.virtualWrite(V2,0);delay(50);
  Blynk.virtualWrite(V3,0);delay(50);
  Blynk.virtualWrite(V4,0);delay(50);
  Blynk.virtualWrite(V5,0);delay(50);
  Blynk.virtualWrite(V6,0);delay(50);
  Blynk.virtualWrite(V6,0);delay(100);
  Blynk.virtualWrite(V0,0);delay(50);

 digitalWrite(fan, 0);delay(50);
 digitalWrite(light1, 0);delay(50);
 digitalWrite(light2, 0);delay(50);
 digitalWrite(light3, 0);delay(50);
 digitalWrite(light4, 0);delay(50);
 
  noTone(buzz);
  tone(buzz, 3000, 200);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz, 2800, 1000);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz,2000, 300);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz,3000, 500);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz,2500, 200);
  delay(500);
   

 BUZZ();
 BUZZ();
 e==0;
 }
}

void WIFIOFF()
{
 e==0;
 BUZZ();
 BUZZ();
}

/*
void zero_crosss_int()  //function to be fired at the zero crossing to dim the light
{
                      // Firing angle calculation : 1 full 50Hz wave =1/50=20ms 
                      // Every zerocrossing thus: (50Hz)-> 10ms (1/2 Cycle) 
                      // For 60Hz => 8.33ms (10.000/120)// 10ms=10000us  
                      // (10000us - 10us) / 128 = 75 (Approx) For 60Hz =>65
  
  volatile int dimtime = (75*dimming);    // For 60Hz = 65    
  delayMicroseconds(dimtime);             // (off cycle)Wait till firing the TRIAC    
  digitalWrite(LOAD, HIGH);               // Fire the TRIAC
  delayMicroseconds(10);                  // triac On propogation delay 
                                          // (for 60Hz use 8.33) Some Triacs need a longer period
  digitalWrite(LOAD, LOW);               // No longer trigger the TRIAC (the next zero crossing will swith it off) TRIAC
}*/

BLYNK_CONNECTED()
{
 // Change Web Link Button message to "Congratulations!"
 // Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
 //Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
 //Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
  Blynk.virtualWrite(V11,"ONLINE");
  Blynk.syncVirtual(V1, light); 
  Blynk.syncVirtual(V2, nightlight);
  Blynk.syncVirtual(V3, conlight);
  Blynk.syncVirtual(V4, con2light);
  Blynk.syncVirtual(V5,  Value);
  Blynk.syncVirtual(V6, alllight );
  Blynk.syncVirtual(V7, galllight );
  Blynk.syncVirtual(V0, Slider_Value);

 a = 0;
 b = 0;
 c = 0;
 d = 0;
  Blynk.virtualWrite(V1,0);
  Blynk.virtualWrite(V2,0);
  Blynk.virtualWrite(V3,0);
  Blynk.virtualWrite(V4,0);
  Blynk.virtualWrite(V5,0);
  Blynk.virtualWrite(V6,0);
  Blynk.virtualWrite(V7,0);
  Blynk.virtualWrite(V0,0);
  
}

void checkBlynkStatus()
{ // called every 3 seconds by SimpleTimer
 bool isconnected = Blynk.connected();
 if (isconnected == false) 
  {
   wifiFlag = 1;
   digitalWrite(wifiLed, LOW); //Turn off WiFi LED
  }
 if (isconnected == true)
  {
   wifiFlag = 0;    
   digitalWrite(wifiLed, HIGH); //Turn on WiFi LED
  }
}

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V10, millis() / 1000);
}

void ir_remote()
{
 if (irrecv.decode(&results)) 
  {
     switch(results.value)
      {
          case 0xFD906F:  all_SwitchOff(); break;
          case 0xFDB04F:  all_SwitchOn(); break;
          case 0xFD7A85:  Light1(); break;
          case 0xFD609F:  Light2(); break;
          case 0xFDA05F:  Light3(); break;
          case 0xFDE21D:  Light4(); break;
          case 0xFDE01F:  Light5(); break;
          case 0xFD9A65:  Fanonoff(); break;
          case 0xFD8A75:  all_LightOnOff(); break;
          case 0xFD58A7:  WIFION(); break;
          case 0xFD708F:  WIFIOFF(); break;
          //case 0xFD12ED:  Fanspeedup(); break;
          //case 0xFDAA55:  Fanspeeddown(); break;          
          default : break;         
      }   
       //Serial.println(results.value, HEX);    
        irrecv.resume();   
  } 
}

//void ICACHE_RAM_ATTR zero_crosss_int ();

void setup()
{ 
 digitalWrite(fan, 0);
 Serial.begin(115200);
 irrecv.enableIRIn();

 
 timer.setInterval(1000L, myTimerEvent);
  
 pinMode(buzz, OUTPUT); 
 pinMode(wifiLed, OUTPUT);  
 pinMode(light1, OUTPUT);
 pinMode(light2, OUTPUT);
 pinMode(light3, OUTPUT);
 pinMode(light4, OUTPUT);
 pinMode(fan, OUTPUT);
 pinMode(light5, OUTPUT);// Set AC Load pin as output
 //pinMode(ZVC,INPUT_PULLUP);
 
 //attachInterrupt(digitalPinToInterrupt(ZVC), zero_crosss_int, RISING);  // Choose the zero cross interrupt pin from any GPIO pin of NodeMCU

 /*Blynk.virtualWrite(V1, light);
 Blynk.virtualWrite(V2,  nightlight);
 Blynk.virtualWrite(V3, conlight);
 Blynk.virtualWrite(V4,  con2light);
 Blynk.virtualWrite(V5,  Value);
 Blynk.virtualWrite(V6, alllight);
 Blynk.virtualWrite(V0, Slider_Value);*/
 

 digitalWrite(fan, 0);delay(50);
 digitalWrite(light1, 0);delay(50);
 digitalWrite(light2, 0);delay(50);
 digitalWrite(light3, 0);delay(50);
 digitalWrite(light4, 0);delay(50);
 digitalWrite(light5, 0);delay(50);
 
  noTone(buzz);
  tone(buzz, 3000, 200);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz, 2800, 1000);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz,2000, 300);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz,3000, 500);
  delay(500);
  noTone(buzz);
  delay(100);
  tone(buzz,2500, 200);
  delay(500);
   
}

void loop()
{
 ir_remote();
 ST_V6();
 if(e==1)
 {
 if (WiFi.status() == WL_CONNECTED)
 {
  Blynk.run();
  
 }
 }
 else
 {
  ir_remote();
 }
 timer.run();

 //dimming=map(Slider_Value, 0, 100, 128, 8);   // at lower values than 8 , flickering may start at 100% so keeping it 8 for avoiding flickering
 delay(10);
 //Serial.println(Slider_Value);  
}
