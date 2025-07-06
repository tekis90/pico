#include "pico/stdlib.h"

const uint LED_PIN = 25;

int main() {

    // The pin named LED_PIN is initialized
    gpio_init(LED_PIN);
     
    // The LED_PIN is set as an output
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // Set the pin HIGH (turn LED on)
        gpio_put(LED_PIN, 1);
        sleep_ms(500);

        // Set the pin LOW (turn LED off)
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }
}
