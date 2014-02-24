/*
 * common.h
 *
 *  Created on: 2009-5-26
 *      Author: lele
 */

#ifndef COMMON_H_
#define COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include	<errno.h>
#include	<stdarg.h>
#include <unistd.h>
#include	<sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <wait.h>
#include <netdb.h>
#include <ctype.h>

#define SERVER_PORT 8088
#define MAX_LIST_ITEM 5
#define MAX_URL_ADDR 20
#define MAX_BUF_SIZE 2048
#define STRING_SIZE 256
#define MAX_PARAM_LENGTH 512

#ifndef NULL
#define NULL 0
#endif
/**
 * 定义拒绝访问列表结构
 */
typedef
	struct {
	char addr [MAX_URL_ADDR];
}refuse_table_item;

//tcp.c
int bind_port(int port);
int connect_to_server(char* server,int port);

int reception(int fd,struct sockaddr_in *from);
//util.c
int parseURL(char* url,char* protocol,char* host,char* port,char* path);
//http.c
int get(char * urls,char* opt,int clientfd);
int post(char * urls,char* param,int clientfd);
int head(char * urls,int childfd);
//generate.c
int generate_errorhead(int errorno,int childfd);
int generate_errorpage1(int childfd);
int generate_errorpage2(int childfd);
#endif /* COMMON_H_ */