#include <stdio.h>
#include "mgos.h"
#include "mgos_gpio.h"

void timerCallback(void *args)
{
  printf("ping!\n");
 
  (void)args;
}

enum mgos_app_init_result mgos_app_init(void)
{
  mgos_set_timer(1000, true, timerCallback, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
