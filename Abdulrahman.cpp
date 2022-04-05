//Library Function Created 26/03/2020

#include "Arduino.h"
#include "abdulrahman.h"

//Delay Library
delayy::delayy()
{
}

void delayy::sec(float t)
{
	delay(t * 1000); 
}
void delayy::minute(float t)
{
	delay(t * 1000 * 60);
}
void delayy::hour(float t)
{
	delay(t * 1000 * 60 * 60);
}
void delayy::day(float t)
{
	delay(t * 1000 * 60 * 60 * 24);
}
void delayy::milli(float t)
{
	delay(t);
}


//Blink Without Delay

blkwd::blkwd()
{
}

void blkwd::idle(unsigned int pin)
{
  t1 = 100;
  t2 = 2000;

  cms = millis();
  if((state == 1) && (cms - pms >= t1))
  {
    state = 0;
    pms = cms;
    digitalWrite(pin, state);
   }
    else if((state == 0) && (cms - pms >= t2))
  {
    state = 1;
    pms = cms;
    digitalWrite(pin, state);
   }
}

void blkwd::flash(unsigned int pin, float toff)
{
  t1 = 100;
 toff *= 1000;

  cms = millis();
  if((state == 1) && (cms - pms >= t1))
  {
    state = 0;
    pms = cms;
    digitalWrite(pin, state);
   }
    else if((state == 0) && (cms - pms >= toff))
  {
    state = 1;
    pms = cms;
    digitalWrite(pin, state);
   }
}

void blkwd::at(unsigned int pin, float t)
{
  t *= 1000;

  cms = millis();
  if(cms - pms >= t)
  {
     pms = cms;
     if(state == 0) state = 1;
     else state = 0;
     digitalWrite(pin, state);
  }
}

void blkwd::toggle(unsigned int pin, float ton, float toff)
{
  ton *= 1000;
 toff *= 1000;

  cms = millis();
  if((state == 1) && (cms - pms >= ton))
  {
    state = 0;
    pms = cms;
    digitalWrite(pin, state);
   }
    else if((state == 0) && (cms - pms >= toff))
  {
    state = 1;
    pms = cms;
    digitalWrite(pin, state);
   }
}


//Blink With Delay
blk::blk(unsigned int i)
{
   digitalWrite(i, 1);
   delay(500);
   digitalWrite(i, 0);
   delay(500);
}



//Relay Module
relay::relay()
{
}
void relay::mode(unsigned int i)
{
   pinMode(i, 1);
}
void relay::high(unsigned int i)
{
   digitalWrite(i, 0);
}
void relay::low(unsigned int i)
{
   digitalWrite(i, 1);
}
void relay::on(unsigned int i)
{
   digitalWrite(i, 0);
}
void relay::off(unsigned int i)
{
   digitalWrite(i, 1);
}


//Pin State Declaration
output::output(unsigned int i)
{
  pinMode(i, 1);
}


input::input(unsigned int i)
{
  pinMode(i, 0);
}


//Pin Status
on_pin::on_pin(unsigned int i)
{
  digitalWrite(i, 1);
}

high::high(unsigned int i)
{
  digitalWrite(i, 1);
}


off_pin::off_pin(unsigned int i)
{
  digitalWrite(i, 0);
}

low::low(unsigned int i)
{
  digitalWrite(i, 0);
}


//General Pin Function
pin::pin()
{
}
void pin::output(unsigned int i)
{
   pinMode(i, 1);
}
void pin::input(unsigned int i)
{
   pinMode(i, 0);
}
void pin::high(unsigned int i)
{
   digitalWrite(i, 1);
}
void pin::low(unsigned int i)
{
   digitalWrite(i, 0);
}
void pin::on(unsigned int i)
{
   digitalWrite(i, 1);
}
void pin::off(unsigned int i)
{
   digitalWrite(i, 0);
}


//Math Function
math::math()
{
}
double math::roundup(float val, float dp)
{
  mult = powf(10.0f, dp);
  val = roundf(val * mult)/mult;
   return val;
}


//Proximity Sensor Calibratiion
proximity::proximity(unsigned int sens_pin)
{
   pin = sens_pin;
}
double proximity::scan()
{
      for(k = 1; k <= n; k++)freq += analogRead(pin);
      freq /= n;
      return freq;
}
double proximity::accuracy(unsigned int j)
{
      for(k = 1; k <= j; k++)freq += analogRead(pin);
      freq /= j;
      return freq;
}


//ADC Conversion

adc::adc(unsigned int pin)
{
   i = pin;
}
unsigned int adc::scan()
{
   j = analogRead(i);
   return j;
}
unsigned int adc::read()
{
   j = analogRead(i);
   return j;
}


//PWM Conversion
pwm::pwm(unsigned int pin)
{
   i = pin;
}
void pwm::output(unsigned int j)
{
   analogWrite(i, j);
}
void pwm::write(unsigned int j)
{
   analogWrite(i, j);
}

//ADC TO PWM
adc2pwm::adc2pwm()
{
}
unsigned int adc2pwm::convert(unsigned int i)
{   
    j = (244 * i) / 1023;
        return j;
}


//PWM TO ADC
pwm2adc::pwm2adc()
{
}
int pwm2adc::convert(unsigned int j)
{
   i = (1023 * j) / 244;
        return i;
}


//Serial Communication
comm::comm()
{
}
void comm::std()
{
  Serial.begin(9600);
}
void comm::at(unsigned int i)
{
  Serial.begin(i);
}

serial::serial()
{
   Serial.begin(9600);
}

writeln::writeln(String i)
{
Serial.println(i);
}


//Frequency Meter
frequency::frequency(unsigned int input)
{
   pinMode(input, 0);
   pin = input;
}
double frequency::scan()
{
      n = 10;
      for(k = 1; k <= n; k++){
      Htime = pulseIn(pin, 1);
      Ltime = pulseIn(pin, 0);
      Ttime = Htime + Ltime;
      freq += 1000000/Ttime;
      }
      freq /= n;
      return freq;
}
double frequency::accuracy(unsigned int n)
{
      for(k = 1; k <= n; k++){
      Htime = pulseIn(pin, 1);
      Ltime = pulseIn(pin, 0);
      Ttime = Htime + Ltime;
      freq += 1000000/Ttime;
      }
      freq /= n;
      return freq;
}

software::software()
{
}
void software::snd(String j)
{
Serial.println(j);
}

timer::timer()
{
}

bool timer::count(float tme)
{
    cms = millis();
              
    if(cms - pms >= tme * 1000)
    {
       pms = cms;
       st = true;
    }
    else st = false;

    return st;
}

rst::rst()
{
    resetFunc();
}

//Receiving From Computer @26/03/2020

