/*
 * WifiHandler.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: mehranshafiei
 */

#include "WifiHandler.h"
#include "esp_log.h"
#include "tcpip_adapter.h"
#include "esp_wifi.h"


static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
//        wifi_connect();
        break;
//    case SYSTEM_EVENT_STA_GOT_IP:
//        xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
//        break;
//    case SYSTEM_EVENT_STA_DISCONNECTED:
//        esp_wifi_connect();
//        xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
//        break;
    default:
        break;
    }
    return ESP_OK;
}

void WifiHandler::Initialize()
{
	printf("Initializing Wifi Handler\n");
	m_wifi_event_group = xEventGroupCreate();

    esp_log_level_set("wifi", ESP_LOG_NONE); // disable wifi driver logging
    tcpip_adapter_init();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_start() );

    printf("Esp WIFI started\n");
    wifi_scan_config_t scanConfig;
    scanConfig.show_hidden = true;
//    esp_wifi_scan_start(&scanConfig, true);
//    esp_wifi_scan_get_ap_records()
}

