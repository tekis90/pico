PWM Frequency and Duty Control on Raspberry Pi Pico
This project demonstrates how to generate and control PWM signals on Raspberry Pi Pico using the Pico SDK (C language).
It includes functions to configure PWM, change duty cycle, and adjust PWM frequency during runtime.

 Features
✔ Configure PWM on any GPIO pin
✔ Change duty cycle (0–100%) dynamically
✔ Change PWM frequency at runtime
✔ Example toggles frequency between 1 kHz and 500 Hz every 5 seconds

pwmConf(pin, fPwm, wrap, dutyPercent)
Initializes PWM on a given pin with specified frequency, wrap value, and duty cycle.

changePwmDuty(pin, dutyPercent)
Updates the duty cycle during runtime without affecting frequency.

setPwmFrequency(pin, fPwm)
Changes the PWM frequency during runtime by updating the divider.

