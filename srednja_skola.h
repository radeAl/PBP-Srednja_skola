#ifndef SREDNJA_SKOLA_H
#define SREDNJA_SKOLA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <mysql/mysql.h>
#include <stdarg.h>

#define _GNU_SOURCE

#define QUERY_SIZE 256
#define BUFFER_SIZE 100
#define DATE_SIZE 12

MYSQL *connection;

char query[QUERY_SIZE];
char answer[3];

typedef struct ocene
{	int id_predmeta;
	char naziv[BUFFER_SIZE];
	char datum[DATE_SIZE];
	int ocena[BUFFER_SIZE];
	int broj_ocena;
}Ocene;


#define check(exp,msg) do \
						{\
							if (!(exp))\
							{\
								errorFatal(msg,__FILE__ ,__LINE__);\
							}\
						} while (0);

void errorFatal(const char* msg,const char* fileName,const int lineNumber);

void print(MYSQL_RES* result);

void zaglavlje(char* nsalov);
void podkategorija(char* nsalov);

MYSQL_RES* executeQuery(char* query);

void chooseOption();
void ucenici(MYSQL* connection);
void nastavnici(MYSQL* connection);
void odeljenja(MYSQL* connection);
void predmeti(MYSQL* connection);
void smerovi(MYSQL* connection);


void pretrazi_ucenika(MYSQL* connection);
void prikazi_ucenika(int id, MYSQL* connection);
void dodaj_ucenika(MYSQL* connection);
void ukloni_ucenika(int id, MYSQL* connection);
void izmeni_ucenika(int id, MYSQL* connection);
void izmeni_osnovne_podatke(int id, MYSQL* connection);
void izmeni_staratelja(int id, MYSQL* connection);
void promeni_status(int id, MYSQL* connection);
void promeni_odeljenje(int id, MYSQL* connection);

void pretrazi_nastavnika(MYSQL* connection);
void prikazi_nastavnika(int id, MYSQL* connection);
void dodaj_nastavnika(MYSQL* connection);
void izmeni_nastavnika(int id, MYSQL* connection);

void pretrazi_predmete(MYSQL* connection);
void dodaj_predmet(MYSQL* connection);
void prikazi_predmet(int id, MYSQL* connection);
void dodeli_nastavnika(int id, MYSQL* connection);

void pretrazi_smerove(MYSQL* connection);
void prikazi_smer(int id, MYSQL* connection);
void dodaj_smer(MYSQL* connection);
void dodaj_smeru_predmet(int id, MYSQL* connection);


#endif
