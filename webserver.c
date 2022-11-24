 #include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"
#include "hardware/adc.h"
#include "pico/multicore.h"

#include "tusb_lwip_glue.h"

#define LED_PIN     25

int temp = 0;

// let our webserver do some dynamic handling
static const char *cgi_toggle_led(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    gpio_put(LED_PIN, !gpio_get(LED_PIN));
    return "/index.shtml";
}

static const char *cgi_reset_usb_boot(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    reset_usb_boot(0, 0);
    return "/index.shtml";
}

static const char *cgi_return_temp(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    return "/temp.shtml";
}

static const tCGI cgi_handlers[] = {
  {
    "/temp",
    cgi_return_temp
  }
};

u16_t adc_ssi_handler(int iIndex, char *buf, int buflen, u16_t current_tag_number, u16_t *next_tag_number)
{
    sprintf(buf, "%d", temp);
    return strlen(buf);
}

const char * ssi_tags[] = {
	   "adc"
};

void core1_entry()
{
    // Initialize tinyusb, lwip, dhcpd and httpd
    init_lwip();
    wait_for_netif_is_up();
    dhcpd_init();
    httpd_init();
    http_set_cgi_handlers(cgi_handlers, LWIP_ARRAYSIZE(cgi_handlers));
    http_set_ssi_handler(adc_ssi_handler, ssi_tags, LWIP_ARRAYSIZE(ssi_tags));
    
    // For toggling the_LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        tud_task();
        service_traffic();
    }
}


int main()
{
    multicore_launch_core1(core1_entry);

    int LED_SENSOR = 26;
    
    stdio_init_all();
    adc_init();
    adc_gpio_init(LED_SENSOR);
    adc_select_input(0);

    const float conversion_factor = 3.3f / (1 << 12);
    while (true)
    {
        uint16_t result = adc_read();
        temp = 100 * (result * conversion_factor) - 50;
        sleep_ms(1000);
    }

    return 0;
}
