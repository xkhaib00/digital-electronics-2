#ifndef F_CPU
#define F_CPU 16000000UL // CPU frequency
#endif
#include <avr/io.h>
#include <util/delay.h>
#define DELAY 1000

int main(void)
{
 // reset timer settings
 TCCR0A = 0;
 TCCR0B = 0;
 // set PWM pin as output
 DDRD |= (1<<PD6) | (1<<PD5);
 // set timer mode Fast PWM
 TCCR0A |= (1<<WGM01) | (1<<WGM00); // Fast PWM with TOP=MAX
 // set output mode
 TCCR0A |= (1<<COM0A1);               // non-inverting mode for OC0A
 TCCR0A |= (1<<COM0B1); // inverting mode for OC0B
 // set prescaller
 TCCR0B |= (1<<CS01) | (1<<CS00); // 64

 // main loop
 while (1)
 {
  /*  
 for (uint8_t i=0;i<250;i+=25)
 {
 OCR0A = i;
 OCR0B = i;
 _delay_ms(100);
 }

 for (uint8_t i=250;i>0;i-=25)
 {
 OCR0A = i;
 OCR0B = i;
 _delay_ms(100);
 }
 OCR0A = 0;
 OCR0B = 0;
 //_delay_ms(DELAY);
 */
  /*
  OCR0A = 13;
  _delay_ms(DELAY);
  OCR0A = 19;
  _delay_ms(DELAY);
  OCR0A = 25;
  _delay_ms(DELAY);
  OCR0A = 19;
  _delay_ms(DELAY);
  OCR0A = 13;
  _delay_ms(DELAY);*/


  for (uint8_t i=0;i<250;i+=25) 
 {
 OCR0A = i;
 _delay_ms(500);
 }

 for (uint8_t i=250;i>=0;i-=25)
 {
 OCR0A = i;
 _delay_ms(500);
 }

 }

}