#ifndef SREDNJA_SKOLA_H
#define SREDNJA_SKOLA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <mysql.h>
#include <stdarg.h>

#define QUERY_SIZE 256
#define BUFFER_SIZE 100

MYSQL *connection;

char query[QUERY_SIZE];
char answer[3];

#define check(exp,msg) do \
						{\
							if (!(exp))\
							{\
								errorFatal(msg,__FILE__ ,__LINE__);\
							}\
						} while (0);

void errorFatal(const char* msg,const char* fileName,const int lineNumber);

void print(MYSQL_RES* result);

MYSQL_RES* executeQuery(char* query);

void chooseOption();

#endif