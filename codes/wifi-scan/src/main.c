#include "mgos.h"
//#include "mgos_rpc.h"
//#include <stdlib.h>

//#include "common/json_utils.h"

// static void wifi_scan_cb(int n, struct mgos_wifi_scan_result *res, void *arg)
// {
//   printf("WiFi scan result: SSIDs %d, arg %p, results:", n, arg);
//   for (int i = 0; i < n; i++)
//   {
//     LOG(LL_INFO, ("  SSID: %-32s, auth: %2d, channel: %2d, RSSI: %2d",
//                   res[i].ssid, res[i].auth_mode, res[i].channel, res[i].rssi));
//   }
//   LOG(LL_INFO, ("WiFi scan done."));
//   (void)arg;
// }

// static void wifiScanRPCHandler(struct mg_rpc_request_info *ri, void *cb_arg,
//                             struct mg_rpc_frame_info *fi, struct mg_str args)
// {
//   mgos_wifi_scan(wifi_scan_cb, NULL);
//
//   mg_rpc_send_responsef(ri, "Done\n");
//
//   (void) cb_arg;
//   (void) fi;
//   (void) args;
// }

// static int wifi_scan_result_printer(struct json_out *out, va_list *ap) {
//   int len = 0;
//   int num_res = va_arg(*ap, int);
//
//   const struct mgos_wifi_scan_result *res =
//       va_arg(*ap, const struct mgos_wifi_scan_result *);
//
//   for (int i = 0; i < num_res; i++) {
//     if (i > 0) len += json_printf(out, ", ");
//     len +=
//         json_printf(out, "{ssid: %Q, auth: %d, channel: %d, rssi: %d}",
//                     res[i].ssid, res[i].auth_mode, res[i].channel, res[i].rssi);
//   }
//
//   return len;
// }
//
// static void wifi_scan_cb(int n, struct mgos_wifi_scan_result *res, void *arg) {
//   struct mg_rpc_request_info *ri = (struct mg_rpc_request_info *) arg;
//
//   if (n < 0) {
//     mg_rpc_send_errorf(ri, n, "wifi scan failed");
//     return;
//   }
//   mg_rpc_send_responsef(ri, "{results: [%M]}", wifi_scan_result_printer, n,
//                         res);
// }
//
// static void wifiScanRPCHandler(struct mg_rpc_request_info *ri,
//                                        void *cb_arg,
//                                        struct mg_rpc_frame_info *fi,
//                                        struct mg_str args) {
//   if (!fi->channel_is_trusted)
//   {
//     mg_rpc_send_errorf(ri, 403, "unauthorized");
//     ri = NULL;
//     return;
//   }
//
//   mgos_wifi_scan(wifi_scan_cb, ri);
//
//   (void) args;
//   (void) cb_arg;
// }
//
// static void wifiConfigRPCHandler(struct mg_rpc_request_info *ri,
//                                        void *cb_arg,
//                                        struct mg_rpc_frame_info *fi,
//                                        struct mg_str args) {
//   if (!fi->channel_is_trusted)
//   {
//     mg_rpc_send_errorf(ri, 403, "unauthorized");
//     ri = NULL;
//     return;
//   }
//
//   mgos_wifi_scan(wifi_scan_cb, ri);
//
//   (void) args;
//   (void) cb_arg;
// }
//
// static void wifi_cb(enum mgos_net_event ev,
//                     const struct mgos_net_event_data *ev_data, void *arg)
// {
//   if (ev_data->if_type != MGOS_NET_IF_TYPE_WIFI) return;
//   LOG(LL_INFO, ("WiFi change event: %d, arg %p", (int) ev, arg));
// }

enum mgos_app_init_result mgos_app_init(void)
{
  //struct mg_rpc *c = mgos_rpc_get_global();
  //mg_rpc_add_handler(c, "Wifi.Scan", "", wifiScanRPCHandler, NULL);
  //mg_rpc_add_handler(c, "Wifi.Config", "", wifiConfigRPCHandler, NULL);

  //mgos_net_add_event_handler(wifi_cb, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
