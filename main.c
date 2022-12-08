#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"

#include "webserver.h"

#define LED_PIN 25

float temp = 0;
int moving_average = 0;

int main()
{
    multicore_launch_core1(core1_entry);

    int TEMP_SENSOR = 26;
    
    stdio_init_all();
    
    adc_init();
    adc_gpio_init(TEMP_SENSOR);
    adc_select_input(0);

    const float conversion_factor = 3.3f / (1 << 12);

    float temps[20] = {0};
    int counter = 0;
    while (true)
    {
        uint16_t result = adc_read();
        temp = 100 * (result * conversion_factor) - 50;

        temps[counter] = temp;
        counter = (counter + 1) % 20;

        if (moving_average)
        {
            float buf = 0;
            for (int i = 0; i < 20; i++)
            {
                buf += temps[i];
            }
            temp = buf / 20;
        }

        sleep_ms(10);
    }

    return 0;
}
