#ifndef _CONFIG_H_
#define _CONFIG_H_

/* PINOUT */
// Pins where the LEDs are connected to
const uint8_t led_pins[] = {
    2,    // button 1 led
    4,    // button 2 led
    6,    // button 3 led
    8,    // button 4 led
    10,   // button 5 led
    12,   // button 6 led
    18,   // button 7 led
    20,   // misc button 1 led
    22,   // misc button 2 led
    14,   // misc button 3 led
    16    // misc button 4 led
};

// Pins where the buttons are connected to
const uint8_t button_pins[] = {
    3,    // button 1
    5,    // button 2
    7,    // button 3
    9,    // button 4
    11,   // button 5
    13,   // button 6
    19,   // button 7
    21,   // misc button 1
    23,   // misc button 2
    15,   // misc button 3
    17    // misc button 4
};

// Pins where the encoder is connected to
const uint8_t encoder_pin0 = 0;  // green wire (a phase)
const uint8_t encoder_pin1 = 1;  // white wire (b phase)

/* OPTIONS */
// Your encoder pulses per rotation
#define ENCODER_PPR 600

// The manufacturer name of this controller
#define MF_NAME "username"

// Set the ability to spoof the beatmania IIDX controller premium model (enable this if you plan on playing infinitas)
#define KONAMI_SPOOF 0

// Number of increments before a full turn is reached
// Set to 72 for 60Hz IIDX, 144 for 120Hz IIDX, 255 for 1 to 1
#define INCREMENTS_PER_FULL_TURN 72

// Set the ability to set sensitivity via spice
#define NO_SENSITIVITY 1

/* OPTIONS YOU PROBABLY DON'T HAVE TO TOUCH */
// Button debouncing time, make this higher if you experience bouncing in your buttons
#define MS_DEBOUNCE 5

// Amount of ms to wait before sending another report
#define REPORT_DELAY 1000

// Enable faster read/write for encoder handling
#define READFAST 1

// This is (cpu_clock_frequency / prescaler / desired_interrupt_frequency)
// for example, set to 133 for 0.5ms (2kHz)  on a 16MHz processor: (16000000L / 64 / 2000  -> 133)
// for example, set to 50  for 0.2ms (5kHz)  on a 16MHz processor: (16000000L / 64 / 5000  -> 50)
// for example, set to 25  for 0.1ms (10kHz) on a 16MHz processor: (16000000L / 64 / 10000 -> 25)
#define INTERRUPT_PERIOD 25

#if READFAST == 1
    #include "digitalWriteFast.h"
    #define IO_WRITE(X, Y) digitalWriteFast(X, Y)
    #define IO_READ(X) digitalReadFast(X)
    #define IO_MODE(X, Y) pinModeFast(X, Y)
#else
    #define IO_WRITE(X, Y) digitalWrite(X, Y)
    #define IO_READ(X) digitalRead(X)
    #define IO_MODE(X, Y) pinMode(X, Y)
#endif

#endif
