/*
  
  This example code is in the public domain.

  modified 19 july 2015
  by Eduardo Nascimento


*/



#include <IRremote.h>
#include <IRremoteInt.h>

#define RECV_PIN        8
#define RELE_PIN        4

IRrecv irrecv(RECV_PIN);
decode_results results;

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
