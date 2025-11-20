
#include<Arduino.h>
#include <WiFi.h>
#include<stdint.h>

#include "../../APP_CFG.h"
#include "WIFI.h"




static const char* wifi_ssid = NULL;
static const char* wifi_pass = NULL;
static WiFiState current_state = WIFI_STATE_DISCONNECTED;
static int retry_count = 0;
static unsigned long last_attempt_time = 0;



void wifi_init(const char* ssid, const char* password) {
  wifi_ssid = ssid;
  wifi_pass = password;
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(100);
  current_state = WIFI_STATE_CONNECTING;
  retry_count = 0;
}

void wifi_state() {
  unsigned long now = millis();

  switch (current_state) {
    case WIFI_STATE_CONNECTING:
      if (WiFi.status() == WL_CONNECTED) {
        current_state = WIFI_STATE_CONNECTED;
        Serial.println("WiFi Connected!");

} else if (now - last_attempt_time > WIFI_RETRY_INTERVAL_MS) {
        last_attempt_time = now;
        if (retry_count < WIFI_MAX_RETRIES) {
          retry_count++;
          Serial.printf("Attempt %d to connect...\n", retry_count);
          WiFi.begin(wifi_ssid, wifi_pass);
        } else {
          current_state = WIFI_STATE_FAILED;
          Serial.println("WiFi Failed after retries.");
        }
      }
      break;

    case WIFI_STATE_CONNECTED:
      if (WiFi.status() != WL_CONNECTED) {
        current_state = WIFI_STATE_ERROR;
        Serial.println("WiFi disconnected unexpectedly.");
      }
      break;

    case WIFI_STATE_FAILED:
    
      Serial.println("Take recovery action (e.g. reboot)");
      break;

    case WIFI_STATE_ERROR:
      
      Serial.println("WiFi error state. Manual intervention?");
      break;

    default:
      break;
  }
}

WiFiState wifi_get_state() {
  return current_state;
}