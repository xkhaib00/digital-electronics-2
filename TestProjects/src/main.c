#include <avr/io.h>     
#include <util/delay.h>
#include <Arduino.h>

#define LED PD2 
//#define PD2 D2

void setup() {
  
}

int main(void) {

  uint8_t led_value = LOW;
  uint8_t led_value2 = HIGH;
  
  pinMode(LED, OUTPUT);


  while (1){
    digitalWrite(LED, led_value2);
    _delay_ms(300);
    digitalWrite(LED, led_value);
    _delay_ms(1000);

  }

  return 0;

}