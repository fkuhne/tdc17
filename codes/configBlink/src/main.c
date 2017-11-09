#include <stdio.h>
#include "mgos.h"
#include "mgos_gpio.h"

void timerCallback(void *args)
{
  printf("ping!\n");
  mgos_gpio_toggle(2);

  (void)args;
}

enum mgos_app_init_result mgos_app_init(void)
{
  mgos_gpio_set_mode(2, MGOS_GPIO_MODE_OUTPUT);

  int ledInterval = mgos_sys_config_get_configBlink_ledInterval();
  mgos_set_timer(ledInterval, true, timerCallback, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
