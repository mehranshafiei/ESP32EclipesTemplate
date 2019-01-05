/*
 * WifiHandler.h
 *
 *  Created on: Dec 24, 2018
 *      Author: mehranshafiei
 */

#ifndef MAIN_WIFIHANDLER_H_
#define MAIN_WIFIHANDLER_H_

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

class WifiHandler {
public:

	static WifiHandler& GetInstance()
	{
		static WifiHandler instance;
		return instance;
	}

	void Initialize();
	bool ConnectToWifi(uint8_t* idIn,uint8_t* passwordIn);

private:
	WifiHandler()
	: m_isInitialized(false),
	  m_wifi_event_group(NULL) {

	}
	virtual ~WifiHandler() {}


	bool m_isInitialized;
	EventGroupHandle_t m_wifi_event_group;
};

#endif /* MAIN_WIFIHANDLER_H_ */
