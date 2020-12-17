#include <Arduino.h>

#include <usbd_def.h>
#include <usbd_core.h>

#define led_on()      digitalWrite(PC13, LOW)
#define led_off()     digitalWrite(PC13, HIGH)
#define pulse_on()    digitalWrite(PB12, HIGH)
#define pulse_off()   digitalWrite(PB12, LOW)


void pulser(void)
{
  pulse_on();
  delayMicroseconds(10);
  pulse_off();
}

void start_timer_freq(TIM_TypeDef *Instance,uint32_t freq,callback_function_t callback){
  HardwareTimer *MyTim = new HardwareTimer(Instance);
  MyTim->setOverflow(freq, HERTZ_FORMAT);
  MyTim->attachInterrupt(callback);
  MyTim->resume();
}

void setup()
{
  pinMode(PC13, OUTPUT);
  pinMode(PB12, OUTPUT);
  led_on();
  delay(300);
  led_off();

  start_timer_freq(TIM1,100,pulser);

}

void loop()
{
  led_on();
  delay(10);
  led_off();
  delay(1990);
}
