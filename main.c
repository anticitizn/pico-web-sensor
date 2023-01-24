#include <stdio.h>
#include <math.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"

#include "src/webserver.h"

#define LED_PIN 25

float web_data[7] = {0};

int main()
{
    set_sys_clock_khz(200000, true);
    multicore_launch_core1(core1_entry);
    
    stdio_init_all();

    const float conversion_factor = 3.3f / (1 << 12);

    while (true)
    {
        for (int i = 0; i < 7; i++)
        {
            if (web_data[i] < (i+1) * 5000)
            {
                if (i < 4)
                {
                    web_data[i] += (i+1) * 10;
                }
                else
                {
                    web_data[i] += pow(i, i-3);
                }
                
            }
            else
            {
                web_data[i] = 0;
            }
            sleep_ms(1);
        }
    }

    return 0;
}
