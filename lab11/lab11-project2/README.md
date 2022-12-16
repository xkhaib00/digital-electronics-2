# Project 2

Precise generation of several PWM channels. Application of two (or more) Servo motors SG90.

### Team members

* Rishat Khaibullin (responsible for making joystick part of project, schematic of project and it description)
* Marian Dvořáček (responsible for making servo and LCD part of project, flowcharts of functions)

## Hardware description

The goal of this project was to generate a PWM signal using an Arduino board. We used part of the code from the first project, namely joystick manipulation, that is, ADC conversion, displaying data on the LCD and signaling on the LED (for clarity). From the mechanical part, two servo motors were added to the project.

In this project, we used:
1. Arduino UNO
2. Joy-stick (2 ADC channels, 1 push button)
3. 2x Servo motors SG90 (1 digital channel)
4. Digilent PmodCLP LCD module
5. LED
6. Resistor (around 150 ohm)

The Arduino board is capable of generating a PWM signal. For a short time, voltage is applied to the pin, and then nothing is applied, if in this way the voltage is applied and turned off on the pin with a constant frequency, then we will get a PWM signal. The ratio of the duration of the high voltage level and the duration of the low voltage is called the duty cycle. For example, if you apply voltage for 0.5s to a pin and turn it off for 1.5s (period of 2s), then the duty cycle will be 25%, so if an LED with a resistor is connected to this pin, the LED will glow at 25% of its power /brightness. This is the principle of the PWM signal.

![Sketch](images/sk2.PNG)
**Note:** Connection diagram of the project to the Arduino board.

## Software description

The main function code was 280 lines. The entire program used 171 bytes (8.3%) of RAM and 1818 bytes (5.6%) of Flash.

In this project, libraries were used that were previously used in past labs. These are libraries `LCD` for working with a display, an `UART` library for displaying parameters in the console, a `GPIO` library for signal processing on pins, and a `timer.h`. All the work of our project is in the `main.c` file.

After assigning all the pins used, defining global constants, as well as connecting all the necessary libraries, the main function follows. In the main function, the pin mode is assigned as input or output, then the register for ADC conversion is also assigned, Timer1 is turned on with a prescaler of 33 ms, as well as an interrupt. At the end, the program ends with an endless loop, where the functions `ISR(TIMER1_OVF_vect)` and `ISR(ADC_vect)` are processed.

In function `ISR(TIMER1_OVF_vect)`, first of all, ADC conversion for the joystick is started, then there is a part that processes the values from the encoder. In the `main.c` function, the initial value of the `pinALast` encoder was written, which we later compare with the output data. If the signal changes from pin A come first, then we are moving clockwise, if from B, then against. With each movement of the encoder, we increase or decrease the `symbol` value, which is subsequently displayed on the LCD. If the encoder button is pressed, the `symbol` value is changed to the first value, in our case it is `!`.

In function `ISR(ADC_vect)`, you first need to display a symbol, which we will change later. This was implemented with a `marker` that changes to a value that will never be reached, so this condition will only be processed once at the start of the program.
Next, it processes the ADC conversion of two channels in turn using the `switch...case` condition. First, the stream from the ADC0 channel is configured (value `ADMUX = 0b01000000`), then ADC conversion takes place. The joystick sends two analog signals ranging from `0` to `1024`. When the joystick is in neutral position, these parameters are approximately `511`. In this way, we can determine the direction along the axis. By changing the ADC conversion channels, we change the direction of the x, y coordinate axes. At the end of each case condition, the next channel (AD2, `ADMUX = 0b01000001`) is configured. This way we can control more analog pins. When driving, the symbol on the display should not go beyond the LCD display (16x2). For this, a condition was set up when, when increasing the value of `line` 16 and higher, the cursor returned to the corner position. When moving to the left, this value is 255 because the type of the variable is `uint8_t`. Each ADC conversion processing is accompanied by a blinking LED for clarity. Also, the position of the cursor is written out in the internal terminal by `UART`.

![1](images/pos1.PNG) ![1](images/UART1.PNG)

![2](images/pos2.PNG) ![2](images/UART2.PNG)

![3](images/main2.PNG) ![ADC1](images/ADC1.png) ![3](images/ADC2.png) ![3](images/T1.png)

## Video

https://youtu.be/jr4P54etUgs

## References

1. Presentations of lecture
2. Labs files
