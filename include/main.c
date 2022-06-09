#include<Arduino.h>
#include<main.h>
int scl=52;
int sda=53;

#define SDA_HIGH  pinMode(sda,INPUT)
#define SDA_LOW   pinMode(sda,OUTPUT)
#define SCL_HIGH  pinMode(scl,INPUT)
#define SCL_LOW   pinMode(scl,OUTPUT)



int bitt;
void delay_i2c()
{
  delayMicroseconds(1);
}
void starti2c()
{
  SCL_HIGH;
  SDA_HIGH;
  delay_i2c();
  SDA_LOW;
  delay_i2c();
  SCL_LOW;
  delay_i2c();
}

void stopi2c(void)
{
  SDA_LOW;
  delay_i2c();
  SCL_HIGH;
  delay_i2c();
  SDA_HIGH;             
  delay_i2c();
}
void clocki2c()
{
  SCL_HIGH;
  delay_i2c();
  SCL_LOW;
  delay_i2c();
}


int i2c_tx(byte data) {
  
  for (byte bits = 0; bits < 8 ; bits++) {              /////////////1-7 bit
    if(0x80 & data)
    {
      SDA_HIGH;
    }
    else
    {
       SDA_LOW;
    }
    data = data << 1;
    clocki2c();
 }
 SCL_HIGH;SCL_LOW;
 SCL_HIGH;
 pinMode(sda,INPUT_PULLUP);
 int x = digitalRead(sda);
 SCL_LOW;
 delay_i2c();
 stopi2c();
 return x;
      
}


