#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"

#include "tusb_lwip_glue.h"

#define LED_PIN 25

extern float temp;
extern int moving_average;

// web server does some dynamic handling
static const char *cgi_toggle_led(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    gpio_put(LED_PIN, !gpio_get(LED_PIN));
    moving_average = moving_average == 0 ? 1 : 0;
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
  },
  {
    "/led",
    cgi_toggle_led
  }
};

u16_t adc_ssi_handler(int iIndex, char *buf, int buflen, u16_t current_tag_number, u16_t *next_tag_number)
{
    sprintf(buf, "%f", temp);
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
    
    // For toggling the LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        tud_task();
        service_traffic();
    }
}