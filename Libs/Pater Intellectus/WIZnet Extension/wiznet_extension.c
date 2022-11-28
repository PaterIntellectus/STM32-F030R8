/*
 * wiznet_extension.c
 *
 *  Created on: 25 нояб. 2022 г.
 *      Author: Николай
 */

#include "wiznet_extension.h"

void printNetworkInfo(void)
{
  wiz_NetInfo netInfo;
  wizchip_getnetinfo(&netInfo);
  printf(
      "===========================\r\n"
      "NetInfo:\r\n"
      "mac  = %d.%d.%d.%d\r\n"
      "ip   = %d.%d.%d.%d\r\n"
      "sn   = %d.%d.%d.%d\r\n"
      "gw   = %d.%d.%d.%d\r\n"
      "dns  = %d.%d.%d.%d\r\n"
      "dhcp:  %s\r\n"
      "===========================\r\n",
      netInfo.mac[0], netInfo.mac[1], netInfo.mac[2], netInfo.mac[3],
      netInfo.ip[0],  netInfo.ip[1],  netInfo.ip[2],  netInfo.ip[3],
      netInfo.sn[0],  netInfo.sn[1],  netInfo.sn[2],  netInfo.sn[3],
      netInfo.gw[0],  netInfo.gw[1],  netInfo.gw[2],  netInfo.gw[3],
      netInfo.dns[0], netInfo.dns[1], netInfo.dns[2], netInfo.dns[3],
      netInfo.dhcp == 1 ? "static" : "dynamic");
}

