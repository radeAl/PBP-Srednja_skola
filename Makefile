PROGS = srednja_skola
CC = gcc
CCFLAGS	= -std=c99 -g -Wall `mysql_config --cflags --libs` -lm
OBJ 	= srednja_skola.o	\
				nastavnici.o \
				ucenici.o\
				predmeti.c\
				smerovi.c\
				odeljenja.c\
				ocene.c\
			

%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

$(PROGS): $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

.PHONY: clean create trigger insert

create:
	mysql -u root --password='' -D mysql <create.sql
insert:
	mysql -u root --password='' -D mysql <insert.sql

trigger:
	mysql -u root --password='' -D mysql <trigeri.sql



clean:
	rm -rf $(PROGS) rm -rf *.o rm -r *~
