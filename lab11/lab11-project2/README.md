# Project 2

Precise generation of several PWM channels. Application of two Servo motors SG90.

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

> ![Sketch](images/sk2.PNG)
> 
> **Note:** Connection diagram of the project to the Arduino board.

## Software description

The main function code was 255 lines. The entire program used 42 bytes (2.1%) of RAM and 2174 bytes (6.7%) of Flash.


![1](images/pos1.PNG)

## Video

https://youtu.be/jr4P54etUgs

## References

1. Presentations of lecture
2. Labs files
