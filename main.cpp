#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
stdio_init_all();
printf("temperatura\n");

adc_init();

adc_gpio_init(26);
adc_select_input(0);

while (1) {
    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t result = adc_read();
    printf("Raw value: 0x%03x, voltage: %f V, Temperatura: %.2f C \n", result, result * conversion_factor, result * conversion_factor / 0.01);
    sleep_ms(500);
    }
}