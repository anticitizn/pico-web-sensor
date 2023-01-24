#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"

#include "lwip/ip_addr.h"
#include "lwip/tcp.h"

#include "tusb_lwip_glue.h"

#define LED_PIN 25

extern float web_data[7];

// web server does some dynamic handling
static const char *cgi_toggle_led(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    gpio_put(LED_PIN, !gpio_get(LED_PIN));
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
    for (int i = 0; i < 7; i++)
    {
      if (i == 0)
      {
        sprintf(buf + strlen(buf), "%f", web_data[i]);
      }
      else
      {
        sprintf(buf + strlen(buf), ",%f", web_data[i]);
      }
    }
    
    return strlen(buf);
}

const char * ssi_tags[] = {
	   "adc"
};

struct tcp_pcb* testpcb;
err_t error;

uint32_t tcp_send_packet()
{
    char *string = "HEAD /process.php?data1=12&data2=5 HTTP/1.0\r\nHost: dneykov.eu\r\n\r\n ";
    uint32_t len = strlen(string);

    /* push to buffer */
    error = tcp_write(testpcb, string, strlen(string), TCP_WRITE_FLAG_COPY);

    if (error) {
        return 1;
    }

    /* now send */
    error = tcp_output(testpcb);
    if (error) {
        return 1;
    }
    return 0;
}

/* connection established callback, err is unused and only return 0 */
err_t connectCallback(void *arg, struct tcp_pcb *tpcb, err_t err)
{
    tcp_send_packet();
    return 0;
}

err_t tcpRecvCallback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    return 0;
}

err_t tcpSendCallback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    return 0;
}

err_t tcpErrorHandler(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    return 0;
}

void tcp_setup(void)
{
    uint32_t data = 0xdeadbeef;

    /* create an ip */
    const ip_addr_t ip = IPADDR4_INIT_BYTES(23,88,107,53);

    /* create the control block */
    testpcb = tcp_new();    //testpcb is a global struct tcp_pcb
                            // as defined by lwIP


    /* dummy data to pass to callbacks*/

    tcp_arg(testpcb, &data);

    /* register callbacks with the pcb */

    tcp_err(testpcb, tcpErrorHandler);
    tcp_recv(testpcb, tcpRecvCallback);
    tcp_sent(testpcb, tcpSendCallback);

    /* now connect */
    tcp_connect(testpcb, &ip, 80, connectCallback);
}


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

    //tcp_setup();

    while (true)
    {
        tud_task();
        service_traffic();
    }
}