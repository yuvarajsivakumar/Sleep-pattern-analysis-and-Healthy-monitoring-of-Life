#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
const int GSR=A2;
int sensorValue=0;
int gsr_value=0;

float temp;
int tempPin = A5;

float pressure;
float ECG;

int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED = LED_BUILTIN;   //  The on-board Arduion LED
int BPM;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 5;

void setup()
{
pinMode(A2,INPUT);
lcd.clear();
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("SLEEP APNEA");
delay(1000);
Serial.begin(9600);
}

void loop(){
long sum=0;
for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
{
 sensorValue=analogRead(GSR);
sum += sensorValue;
delay(5);
gsr_value = sum/10;
Serial.print("gsr_value = ");
Serial.print(gsr_value); 
Serial.print("micro-Siemens (μS)");
Serial.println();
delay(1000);
lcd.setCursor(0, 0);  
lcd.println("gsr_ value= ");
lcd.print(gsr_value); 
delay(1000);
lcd.clear();   
temp = analogRead(tempPin);
temp = analogRead(A5);
temp = temp * 0.48828125/8;
Serial.print("TEMPERATURE = ");
Serial.print(temp); 
Serial.print("*C");
Serial.println();
delay(1000);
lcd.setCursor(0, 0);  
lcd.print("TEMPERATURE = ");
lcd.print(temp); 
delay(1000);   
lcd.clear();  
pressure= analogRead(A1);
Serial.print("Pressure: ");                     
Serial.println(pressure); 
delay(1000);
lcd.setCursor(0, 0);
lcd.print("Pressure: ");                     
lcd.print(pressure);
delay(1000);
lcd.clear();

ECG=analogRead(A4);
Serial.print("ECG: ");                     
Serial.println(ECG); 
lcd.setCursor(0, 0);  
lcd.print("ECG: ");
lcd.print(ECG); 
delay(1000);   
lcd.clear();
BPM = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.                                              // Assign this value to the "Signal" variable.
Serial.print("BPM: ");                     
Serial.println(BPM/Threshold); 
lcd.setCursor(0, 0);  
lcd.print("BPM: ");
lcd.print(BPM/Threshold); 
delay(1000);   
lcd.clear();
  
}
}
