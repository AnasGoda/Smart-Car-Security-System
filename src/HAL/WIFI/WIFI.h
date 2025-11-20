#ifndef WIFI_H
#define WIFI_H



typedef enum {
  WIFI_STATE_DISCONNECTED,
  WIFI_STATE_CONNECTING,
  WIFI_STATE_CONNECTED,
  WIFI_STATE_FAILED,
  WIFI_STATE_ERROR
} WiFiState;

void wifi_init(const char* ssid, const char* password);
void wifi_state();
WiFiState wifi_get_state();

#endif






