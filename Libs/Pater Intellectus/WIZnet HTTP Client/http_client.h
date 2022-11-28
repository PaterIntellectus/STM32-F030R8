/*
 * http_client.h
 *
 *  Created on: 25 нояб. 2022 г.
 *      Author: Николай
 */

#ifndef HTTP_CLIENT_H_
#define HTTP_CLIENT_H_


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "socket.h"
#include "wizchip_conf.h"


#define HTTPC_DEBUG

#define DATA_BUF_SIZE 2048


static const uint8_t SERVER_IP[4]  = { 192, 168, 1, 23 };
static const uint16_t SERVER_PORT  = 80;
static const uint8_t SERVER_HOST[] = "spectr.kz";


typedef enum {
  GET, POST
} HttpMethod;

typedef struct {
  HttpMethod method;
  uint8_t* uri;
  uint8_t* host;
} Request;


uint8_t httpc_socket(uint8_t sn);
uint8_t httpc_connect(uint8_t sn);
uint8_t httpc_send(uint8_t sn, Request* request);
uint8_t httpc_recv(uint8_t sn);

#endif /* _HTTP_CLIENT_H_ */
