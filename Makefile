PROGS = srednja_skola
CC = gcc
CCFLAGS	= -std=c99 -g -Wall `mysql_config --cflags --libs`
OBJ 	= srednja_skola.o	\
				nastavnici.o \
				ucenici.o\
				predmeti.c\
			

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

$(PROGS): $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

