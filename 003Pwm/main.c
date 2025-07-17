#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint fClock = 125000000; 
uint wrap = 35535;
const uint LED_PIN = 25;
uint time_ = 5000;

void pwmConf(uint pin_, uint fPwm, uint wrapValue, uint dutyPercent) {

  if (dutyPercent > 100) dutyPercent = 100;

  // Set the specified pin to PWM mode
  gpio_set_function(pin_, GPIO_FUNC_PWM);

  // Get slice and channel information
  uint slice_num = pwm_gpio_to_slice_num(pin_);
  uint channel = pwm_gpio_to_channel(pin_);

  // Calculate divider value
  float divider = (float)fClock / (fPwm * (wrapValue + 1));
  if (divider < 1.0f) divider = 1.0f;
  if (divider > 255.0f) divider = 255.0f;

  // Load default PWM configuration
  pwm_config config = pwm_get_default_config();
  pwm_config_set_clkdiv(&config, divider);

  // Initialize PWM
  pwm_init(slice_num, &config, true);

  // Set wrap value (resolution)
  pwm_set_wrap(slice_num, wrapValue);

  // Calculate duty cycle (0–wrapValue)
  uint dutyValue = (dutyPercent * wrapValue) / 100;

  pwm_set_chan_level(slice_num, channel, dutyValue);
}

void changePwmDuty(uint pin, uint dutyPercent) {

  if (dutyPercent > 100) dutyPercent = 100;

  uint slice_num = pwm_gpio_to_slice_num(pin);
  uint channel = pwm_gpio_to_channel(pin);

  uint dutyValue = (dutyPercent * wrap) / 100;

  pwm_set_chan_level(slice_num, channel, dutyValue);
}

void setPwmFrequency(uint pin, uint32_t fPwm) {

  uint slice_num = pwm_gpio_to_slice_num(pin);

  float divider = (float)fClock / (fPwm * (wrap + 1));

  if (divider < 1.0f) divider = 1.0f;
  if (divider > 255.0f) divider = 255.0f;

  // Update PWM configuration
  pwm_set_clkdiv(slice_num, divider);
}

int main() {
  uint fPwm1 = 1000;      // 1 kHz
  uint fPwm2 = 500;       // 500 Hz
  uint duty = 50;         // 50% duty

  pwmConf(LED_PIN, fPwm1, wrap, duty);
  sleep_ms(time_);
  
  while (true) {
    setPwmFrequency(LED_PIN, fPwm2);
    sleep_ms(time_);
    setPwmFrequency(LED_PIN, fPwm1);
    sleep_ms(time_);
  }
}

