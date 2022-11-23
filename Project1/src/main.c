/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD)
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 3)
 *     D7   - PD7 (Data bit 2)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

#define encoder0PinA 11
#define encoder0PinB 12
#define encoder0Btn 10
int encoder0Pos = 0;

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{

    
    
    /*
    // Custom character definition using https://omerk.github.io/lcdchargen/
    uint8_t customChar[8] = {
        0b00111,
        0b01110,
        0b11100,
        0b11000,
        0b11100,
        0b01110,
        0b00111,
        0b00011
    };

    uint8_t customChar2[8] = {
        0b11001,
        0b10011,
        0b00110,
        0b01100,
        0b11001,
        0b10011,
        0b00110,
        0b01100
    };

    uint8_t customChar3[8] = {
        0b10101,
        0b10101,
        0b10001,
        0b10101,
        0b10101,
        0b10001,
        0b10101,
        0b10101
    };

    uint8_t customChar4[8] = {
        0b01010,
        0b10101,
        0b01010,
        0b10101,
        0b01010,
        0b10101,
        0b01010,
        0b10101
    };

    uint8_t customChar5[8] = {
        0b10010,
        0b01001,
        0b10010,
        0b00100,
        0b01001,
        0b00100,
        0b10010,
        0b01001
    };

    uint8_t customChar6[8] = {
        0b00100,
        0b00100,
        0b00100,
        0b11111,
        0b11111,
        0b00100,
        0b00100,
        0b00100
    };

    uint8_t customChar7[8] = {
        0b00110,
        0b00110,
        0b11001,
        0b11001,
        0b00110,
        0b00110,
        0b11001,
        0b11001
    };



    // Initialize LCD display
    lcd_init(LCD_DISP_ON);

    // Set pointer to beginning of CGRAM memory
    lcd_command(1 << LCD_CGRAM);
    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar[i]);
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar2[i]);
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar3[i]);
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar4[i]);
    }
    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar5[i]);
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar6[i]);
    }
    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar7[i]);
    }

    // Set DDRAM address to display characters
    lcd_command(1 << LCD_DDRAM);
 
    // Display first custom character at address 0
    lcd_putc(0x00);

    lcd_gotoxy(2, 0);
    lcd_putc(0x01);

    lcd_gotoxy(4, 0);
    lcd_putc(0x02);

    lcd_gotoxy(6, 0);
    lcd_putc(0x03);

    lcd_gotoxy(8, 0);
    lcd_putc(0x04);

    lcd_gotoxy(10, 0);
    lcd_putc(0x05);

    lcd_gotoxy(12, 0);
    lcd_putc(0x06);

    */

    



    //__________________________________________________________________
    
    // Initialize display
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);

    // Put string(s) on LCD screen
    /*
    lcd_gotoxy(6, 0);
    lcd_puts("LCD Test"); // Zapis Retezce
    lcd_putc('!');        // Zapis symbolu
    */ 
    
    lcd_gotoxy(0, 0);
    lcd_putc(0xf0); // Vypise retezec Sloupec potom Radek
    
    

    

    /*
    // Configuration of 8-bit Timer/Counter2 for Stopwatch update
    // Set the overflow prescaler to 16 ms and enable interrupt
    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();

    uint8_t customChar[] = {
    // addr 0: .....
    0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000,
    // addr 1: |....
    0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000,
    // addr 2: ||...
    0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000,
    // addr 3: |||..
    0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100,
    // addr 4: ||||.
    0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110,
    // addr 4: |||||
    0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111,
    };*/

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD screen every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t no_of_overflows = 0;
    static uint8_t tenths = 0;  // Tenths of a second
    static uint8_t seconds = 0;
    static uint8_t minutes = 0;
    static uint8_t symbol = 0;
    static uint8_t position = 0;
    char string[2];             // String for converted numbers by itoa()

    no_of_overflows++;
    if (no_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        no_of_overflows = 0;

        // Count tenth of seconds 0, 1, ..., 9, 0, 1, ...
        
        tenths++;

        if (tenths > 9)  
        {
          tenths =0;
          seconds++;
          if (seconds > 59)
          {
            seconds =0;
            minutes++;
          }
        }           


        itoa(tenths, string, 10);  // Convert decimal value to string
        // Display "00:00.tenths"
        lcd_gotoxy(7, 0);
        lcd_puts(string);
      
        lcd_gotoxy(6, 0);
        lcd_putc('.'); 

        itoa(seconds, string, 10);
        if (seconds <=9 )
        {
        lcd_gotoxy(5, 0);
        lcd_puts(string);
        lcd_gotoxy(4, 0);
        lcd_putc('0');
        }
        else
        {
        lcd_gotoxy(4, 0);
        lcd_puts(string);
        }

        lcd_gotoxy(3, 0);
        lcd_putc(':'); 

        itoa(minutes, string, 10);
        lcd_gotoxy(2, 0);
        lcd_puts(string);
        lcd_gotoxy(1, 0);
        lcd_putc('0');

        /*
        lcd_gotoxy(11, 0);
        lcd_putc('a');        
        lcd_gotoxy(1, 1);
        lcd_putc('b');        
        lcd_gotoxy(11, 1);
        lcd_putc('c');
        */
       

       //int n = 0;

       if (seconds == 1) 
        {
          lcd_gotoxy(1, 1);
          lcd_putc(0xff);
        }
        if (seconds == 2) 
        {
          lcd_gotoxy(2, 1);
          lcd_putc(0xff);
        }

        //lcd_gotoxy(1 + position, 1);
        //lcd_putc(symbol);



        lcd_gotoxy(16, 1);  


    }
    // Else do nothing and exit the ISR
}