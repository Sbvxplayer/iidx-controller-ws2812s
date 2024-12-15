#include "src/HID/LUFAConfig.h"
#include <LUFA.h>
#include <FastLED.h>
#include "src/HID/IIDXHID.h"
#include "src/IO/Buttons.h"
#include "src/IO/Encoder.h"
#include "src/IO/LEDs.h"
#include "src/Configuration.h"

// LED Strip Configuration
#define LED_PIN 18
#define NUM_LEDS 20  // Adjust to your strip's actual size
#define LED_STRIP_VOLTAGE 5
#define LED_STRIP_MILLIAMPS 1200
CRGB leds[NUM_LEDS];  // Array for LEDs

// Color settings
uint8_t rHue = 0;
#define TT_COLOR CHSV(160, 200, 170)  // Example color for the strip, change as needed

// Configuration structure
static configuration_struct *config;

int lastEncoderState = 0;  // To keep track of the last encoder state
int encoderState = 0;      // To store the current encoder state

void setup() {
    // Initialize configuration, buttons, encoder, LEDs, and hardware
    initialise_configuration();
    initialise_buttons();
    initialise_encoder();
    initialise_leds();
    get_configuration(&config);

    delay(500);
    setup_hardware();
    GlobalInterruptEnable();

    // LED setup for the strip
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_STRIP_VOLTAGE, LED_STRIP_MILLIAMPS);
    FastLED.setCorrection(TypicalSMD5050);  // Correct color correction for WS2812
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(calculate_max_brightness_for_power_vmA(leds, NUM_LEDS, 255, LED_STRIP_VOLTAGE, LED_STRIP_MILLIAMPS));

    // Set the initial color for all LEDs in the strip
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = TT_COLOR;  // Example color for all LEDs
    }
    FastLED.show();
    FastLED.delay(10);
}

void loop() {
    // Handle HID tasks and USB communication
    HID_task();
    USB_USBTask();

    // Read the current encoder state
    encoderState = get_encoder_state();  // Assuming this gives the state of the encoder

    // If the encoder has moved (compared to the last state)
    if (encoderState != lastEncoderState) {
        // Encoder has been turned, so change the LED color based on encoder state
        int hue = (encoderState * 2) % 255;  // Example: create a smooth color transition
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = CHSV(hue, 255, 255);  // Change color based on the encoder's position
        }
        FastLED.show();  // Update LEDs
        lastEncoderState = encoderState;  // Update the last encoder state
    }

    // Update button LEDs (if this function is responsible for button LEDs)
    write_leds(get_button_state(), false);  // Make sure this updates your button LEDs

}

