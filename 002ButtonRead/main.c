
#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 25;

const uint BTN_PIN = 11;

int main() {

  //led
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  //button
  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_down(BTN_PIN); // Add internal pull-down resistor to button pin


  while (true)
  {

    if (gpio_get(BTN_PIN))//reading the button value
    {
      gpio_put(LED_PIN, 1);

    }
    else
    {
      gpio_put(LED_PIN, 0);
    }



  }

}
