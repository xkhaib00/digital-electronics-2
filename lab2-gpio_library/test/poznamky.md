     #define PB5 5          // In Arduino world, PB5 is called "13"
     #define PB0 0
     
     DDRB |= (1<<LED_GREEN);           //<---------------------
            // Set second pin as output
    //pinMode(LED_RED, OUTPUT);
    DDRB |= (1<<LED_RED);             //<---------------------

    // Infinite loop
    while (1)
    {
        
              // Turn ON/OFF on-board LED ...
        //digitalWrite(LED_GREEN, led_value);
        PORTB |= (1<<LED_GREEN);           //<---------------------
              // ... and external LED as well
        //digitalWrite(LED_RED, led_value);
        PORTB |= (1<<LED_RED);           //<---------------------

        _delay_ms(SHORT_DELAY);

        PORTB &= ~(1<<LED_GREEN);
        PORTB &= ~(1<<LED_RED);

        _delay_ms(SHORT_DELAY);

        PORTB ^= (1<<LED_GREEN);
        PORTB ^= (1<<LED_RED);
