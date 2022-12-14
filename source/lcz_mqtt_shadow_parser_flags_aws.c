/**
 * @file lcz_mqtt_shadow_parser_flags_aws.c
 * @brief
 *
 * Copyright (c) 2022 Laird Connectivity
 *
 * SPDX-License-Identifier: LicenseRef-LairdConnectivity-Clause
 */

/**************************************************************************************************/
/* Includes                                                                                       */
/**************************************************************************************************/
#include <string.h>

#include "lcz_mqtt_shadow_parser_flags_aws.h"

/**************************************************************************************************/
/* Global Constants, Macros and Type Definitions                                                  */
/**************************************************************************************************/
#define LCZ_MQTT_SHADOW_PARSER_GATEWAY_TOPIC_STR "deviceId-"
#define LCZ_MQTT_SHADOW_PARSER_GET_ACCEPTED_STR "/get/accepted"

/**************************************************************************************************/
/* Data                                                                                           */
/**************************************************************************************************/
/* This is thread safe because the shadow parser uses a mutex. */
static struct topic_flags topic_flags;

/**************************************************************************************************/
/* Global Function Definitions                                                                    */
/**************************************************************************************************/
struct topic_flags *lcz_mqtt_shadow_parser_find_flags(const char *topic)
{
	topic_flags.get_accepted = (strstr(topic, LCZ_MQTT_SHADOW_PARSER_GET_ACCEPTED_STR) != NULL);

	topic_flags.gateway = (strstr(topic, LCZ_MQTT_SHADOW_PARSER_GATEWAY_TOPIC_STR) != NULL);

	return &topic_flags;
}
