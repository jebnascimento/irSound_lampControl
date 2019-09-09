/*
  
  This example code is in the public domain.

  modified 09 SET 2019
  by Eduardo Nascimento


*/

#include <IRremote.h>

int RECV_PIN = 9;
int LUZ = 6;
int VENT = 5;


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(VENT, OUTPUT);
  pinMode(LUZ, OUTPUT);
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, DEC);
    long int value = results.value;
    Serial.println("\n");
    Serial.println(value);
    if(value == 551536185)
    {
      digitalWrite(LUZ, !digitalRead(LUZ)); 
      delay(500);
    }
    irrecv.resume(); // Receive the next value  
    delay(10);
    
    if(value == 551519865)
    {
      digitalWrite(VENT, !digitalRead(VENT)); 
      delay(500);
    }
    irrecv.resume(); // Receive the next value  
    delay(10);
  }
  delay(100);  
}

