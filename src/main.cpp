#include<Arduino.h>
#include<main.h>
#include<main.c>
void setup() {
  Serial.begin(9600);
}
void loop() {
starti2c();
  for(int i=1;i<=127;i++){
  if(!(i2c_tx(i)))
  {
    Serial.print("_____found at! ");
    Serial.println(i,HEX);
  }
 delay(50);
}
}