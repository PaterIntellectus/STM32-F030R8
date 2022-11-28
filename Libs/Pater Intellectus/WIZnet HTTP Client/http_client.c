/*
 * http_client.c
 *
 *  Created on: 25 нояб. 2022 г.
 *      Author: Николай
 */
#include "http_client.h"

uint8_t httpc_socket(uint8_t sn)
{
  return socket(sn, Sn_MR_TCP, 818, Sn_MR_ND);
}

uint8_t httpc_connect(uint8_t sn)
{
  return connect(sn, SERVER_IP, SERVER_PORT);
}

uint8_t httpc_send(uint8_t sn, Request* request)
{
  uint8_t buffer[DATA_BUF_SIZE] = {};
  int requestLength = 0;

  requestLength += sprintf((char*)buffer,
                           "%s %s HTTP/1.1\r\n",
                           request->method ? "POST" : "GET", request->uri);
  requestLength += sprintf((char*)buffer + requestLength,
                           "Host: %s\r\n", request->host);
  requestLength += sprintf((char*)buffer + requestLength,
                           "Connection: %s\r\n", "keep-alive");
  requestLength += sprintf((char*)buffer + requestLength,
                           "Keep-Alive: %s\r\n", "2000");
  requestLength += sprintf((char*)buffer + requestLength, "\r\n");

#ifdef HTTPC_DEBUG
  printf(
      "======================\r\n"
      "Request:\r\n"
      "%s"
      "Request length: %d\r\n"
      "======================\r\n",
      (char*)buffer, requestLength);
#endif
  return send(sn, buffer, requestLength);
}

uint8_t httpc_recv(uint8_t sn)
{
  uint8_t reply[DATA_BUF_SIZE] = {};
  int32_t replyLen = recv(sn, reply, sizeof(reply));

#ifdef HTTPC_DEBUG
  printf(
      "======================\r\n"
      "Reply:\r\n"
      "%s\r\n"
      "Reply length: %d\r\n"
      "======================\r\n",
      reply, replyLen);
#endif
  return replyLen;
}
