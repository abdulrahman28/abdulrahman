//Library Function Created 26/03/2020

#ifndef Abdulrahman_h
#define Abdulrahman_h

#include "Arduino.h"

//Delay Library
class delayy
{
  public:
    delayy();
    void sec(float t);
    void minute(float t);
    void hour(float t);
    void milli(float t);
    void day(float t);
};


//Blink Without Delay
class blkwd
{
public:
  blkwd();
  void idle(unsigned int pin); 
  void flash(unsigned int pin, float toff);
  void at(unsigned int pin, float t);
  void toggle(unsigned int pin, float ton, float toff);
  
private:
  unsigned long pms = 0, cms;
  unsigned int state = 0, t1, t2;
};


//Blink With Delay
class blk
{
public:
  blk(unsigned int i);
};


//Relay Module
class relay
{
public:
  relay();
  void mode(unsigned int i);
  void high(unsigned int i);
  void low(unsigned int i);
  void on(unsigned int i);
  void off(unsigned int i);
};



//Pin State Declaration
class output
{
public:
  output(unsigned int i);
};

class input
{
public:
  input(unsigned int i);
};


//Pin Status
class on_pin
{
public:
  on_pin(unsigned int i);
}; 

class high
{
public:
  high(unsigned int i);
}; 


class off_pin
{
public:
  off_pin(unsigned int i);
};
 
class low
{
public:
  low(unsigned int i);
};



//General Pin Function
class pin
{
public:
  pin();
  void output(unsigned int i);
  void input(unsigned int i);
  void high(unsigned int i);
  void low(unsigned int i);
  void on(unsigned int i);
  void off(unsigned int i);
};


//Math Function
class math
{
public:
  math();
  double roundup(float val, float dp);
private:
  float mult;
}; 

//Proximity Sensor Calibration
class proximity
{
public:
  proximity(unsigned int sens_pin);
  double scan();
  double accuracy(unsigned int j);
private:
  unsigned int k, pin;
  long freq = 0;
  unsigned int n = 5;
};


//ADC Conversion
class adc
{
public:
  adc(unsigned int pin);
  unsigned int scan();
  unsigned int read();
private:
  unsigned int i, j;
};


//PWM Conversion
class pwm
{
public:
  pwm(unsigned int pin);
  void output(unsigned int j);
  void write(unsigned int j);
private:
  unsigned int i;
};


//ADC TO PWM
class adc2pwm
{
public:
 adc2pwm();
 unsigned int convert(unsigned int i);
private:
  double j;
};


//PWM TO ADC
class pwm2adc
{
public:
  pwm2adc();
  int convert(unsigned int j);
private:
  int i;
};


//Serial Communication
class comm
{
public:
  comm();
  void std();
  void at(unsigned int i);
};

class serial
{
public:
  serial();
};

class writeln
{
public:
writeln(String i);
};


//Frequency Meter
class frequency
{
public:
  frequency(unsigned int input);
  double scan();
  double accuracy(unsigned int n);
private:
  unsigned int k, n, pin, Htime, Ltime;
  long freq = 0;
  float Ttime;
};

class software
{
public:
  software();
  void snd(String j); 
};


class timer
{
public:
  timer();
  bool count(float tme);
private:
  unsigned long cms, pms = 0;
  bool st = false;
};


class rst
{
public:
  rst();
private:
  void(*resetFunc)(void) = 0;
};


//Receiving From Computer @26/03/2020



#endif