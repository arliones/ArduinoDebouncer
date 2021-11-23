/*
 * PinInterruptDebouncer.ino - Debouncer Library usage example.
 * Created by Arliones Hoeller Jr., November 23rd, 2021.
 * Released under the MIT License.
 */
#include <Debouncer.h>

Debouncer _deb0(100); // Debouncer for INT0 with 100ms delay
Debouncer _deb1(70);  // Debouncer for INT1 with 70ms delay

volatile bool pin2, pin3; // Values to store the current pin level
                          // pin2-INT0 / pin3-INT1

void int0handler() // INT0 Interrupt Handler
{
    if (_deb0.debounce()) // If interrupt is valid (debounced)
        pin2 = !pin2; // Pin level changed
}

void int1handler() // INT1 Interrupt Handler
{
    if (_deb1.debounce()) // If interrupt is valid (debounced)
        pin3 = !pin3; // Pin level changed
}

void setup()
{
    Serial.begin(115200); // Initialize serial port

    // Register interrupt handlers and enable interrupts
    attachInterrupt(digitalPinToInterrupt(2), int0handler, CHANGE);
    attachInterrupt(digitalPinToInterrupt(3), int1handler, CHANGE);
}

void loop() // Print pin levels every 50ms
{
    Serial.print(pin2);
    Serial.print("|");
    Serial.println(pin3);
    delay(50);
}

