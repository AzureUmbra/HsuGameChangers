#include <dht.h>

dht DHT;

#define DHT11_PIN 7

const int red = 3;
const int yellow = 5;
const int green = 6;
int pot = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(A0);
  //Serial.print("Pot: " + String(pot) + "\n");
  if (pot >= ((1023/3)*2)+100){digitalWrite(green, HIGH); digitalWrite(yellow, HIGH); digitalWrite(red, HIGH);}
  else if (pot >= ((1023/3))+100){digitalWrite(green, LOW); digitalWrite(yellow, HIGH); digitalWrite(red, HIGH);}
  else if (pot >= 100){digitalWrite(green, LOW); digitalWrite(yellow, LOW); digitalWrite(red, HIGH);}
  else {digitalWrite(green, LOW); digitalWrite(yellow, LOW); digitalWrite(red, LOW);}
  
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
