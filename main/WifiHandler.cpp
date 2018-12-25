/*
 * WifiHandler.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: mehranshafiei
 */

#include "WifiHandler.h"

void WifiHandler::Initialize()
{
	printf("Initializing Wifi Handler\n");
	m_wifi_event_group = xEventGroupCreate();
}

