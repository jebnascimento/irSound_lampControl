#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int relePin = 4;

void setup() 
{
  Serial.begin(9600);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW);
  irrecv.enableIRIn();
}

void loop() 
{
  if(irrecv.decode(&results))
  { 
    delay(10);
    //Serial.println(results.value);
    if( results.value == 16753245) 
      {
        digitalWrite(relePin, !digitalRead(relePin));
        delay(500);
      }
    irrecv.resume();   
  }
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue > 20k)
    {
      digitalWrite(relePin, !digitalRead(relePin)); 
      delay(500);
    }  
  delay(10);        
}
