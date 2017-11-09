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
  mgos_set_timer(1000, true, timerCallback, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
