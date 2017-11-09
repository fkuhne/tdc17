#include "mgos.h"
#include "mgos_mqtt.h"

static void mqttDataReceivedCallback(struct mg_connection *c, const char *topic,
  int topic_len, const char *msg, int msg_len, void *userdata)
{
  printf("Recebendo: [%.*s] no topico: [%.*s]\n", msg_len, msg, topic_len, topic);
  fflush(0);

  (void)c;
  (void)userdata;
}

void timerCallback(void *args)
{
  static int messageCounter = 1;
  char msg[20] = {};

  snprintf(msg, sizeof(msg), "MENSAGEM %d", messageCounter++);
  printf("Enviando:  [%.*s] para o topico: [my/topic]\n", strlen(msg), msg);
  fflush(0);

  mgos_gpio_toggle(2);

  mgos_mqtt_pub("my/topic", msg, strlen(msg), 2, 0);

  (void)args;
}

enum mgos_app_init_result mgos_app_init(void)
{
  mgos_gpio_set_mode(2, MGOS_GPIO_MODE_OUTPUT);
  mgos_set_timer(1000, true, timerCallback, NULL);

  mgos_mqtt_sub("my/subscription", mqttDataReceivedCallback, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
