#include "srednja_skola.h"

void ocene(MYSQL* connection){
	int option;
	zaglavlje("OCENE");


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Dodaj ocenu\n");
	  	printf("2.Zakljuci ocenu\n");
	  
	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 3 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	switch (option) {
	    case 1:
	      dodaj_ocenu(connection);
	      break;
	    case 2:
	      zakljuci_ocenu(connection);
	      break;
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
    
		}
	}

void dodaj_ocenu(MYSQL* connection){
	podkategorija("PRETRAGA UCENIKA");

	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE];
	printf("Unesite ime ucenika kome zelite da unesete ocenu\n");
	scanf("%s", ime);
	printf("Unesite prezime ucenika kome zelite da unesete ocenu\n");
	scanf("%s", prezime);

	sprintf(query, "select * from Ucenik where ime=\'%s\' and prezime = \'%s\'", ime, prezime);
	MYSQL_RES *rezultat = executeQuery(query);
	print(rezultat);

	int id;
	printf("Unesite id ucenika kome zelite da unesete ocenu\n");
	      
	scanf("%d", &id);

	sprintf(query, "select Predmet.id,Predmet.naziv from Odeljenje join Smer on Odeljenje.id_smera = Smer.id\
					join Smer_Predmet on Smer_Predmet.id_smera = Smer.id join\
					Predmet on Predmet.id = Smer_Predmet.id_predmeta join Ucenik on Ucenik.id_odeljenja=Odeljenje.id\
					where Odeljenje.godina = Smer_Predmet.godina and Ucenik.id=%d", id);

	rezultat = executeQuery(query);
	print(rezultat);

	printf("Unesite id predmeta za koji zelite da unesete ocenu\n");
	int id_predmeta;
	scanf("%d", &id_predmeta);

	printf("Unesite id datum za ocenu\n");
	char datum[BUFFER_SIZE];
	scanf("%s", datum);

	printf("Unesite ocenu \n");
	int ocena;
	scanf("%d", &ocena);


	sprintf(query, "insert into Ocena values (%d, %d, \'%s\', %d)", id, id_predmeta, datum, ocena);
	executeQuery(query);

	printf("Uspesno ste uneli ocenu\n");
	prikazi_ucenika(id, connection);


}

void zakljuci_ocenu(MYSQL* connection){
	zaglavlje("ZAKLJUCIVANJE");
	podkategorija("PRETRAGA UCENIKA");

	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE];
	printf("Unesite ime ucenika kome zelite da zakljucite ocenu\n");
	scanf("%s", ime);
	printf("Unesite prezime ucenika kome zelite da zakljucite ocenu\n");
	scanf("%s", prezime);

	sprintf(query, "select * from Ucenik where ime=\'%s\' and prezime = \'%s\'", ime, prezime);
	MYSQL_RES *rezultat = executeQuery(query);
	print(rezultat);

	int id;
	printf("Unesite id ucenika kome zelite da zakljucite ocenu\n");
	      
	scanf("%d", &id);

	sprintf(query, "select Predmet.id,Predmet.naziv from Odeljenje join Smer on Odeljenje.id_smera = Smer.id\
					join Smer_Predmet on Smer_Predmet.id_smera = Smer.id join\
					Predmet on Predmet.id = Smer_Predmet.id_predmeta join Ucenik on Ucenik.id_odeljenja=Odeljenje.id\
					where Odeljenje.godina = Smer_Predmet.godina and Ucenik.id=%d", id);

	rezultat = executeQuery(query);
	print(rezultat);

	printf("Unesite id predmeta koga zelite da zakljucite\n");
	int id_predmeta;
	scanf("%d", &id_predmeta);

	sprintf(query, "select sum(ocena)/count(*) from Ocena where id_predmeta=%d and id_ucenika=%d", id_predmeta, id);
	rezultat = executeQuery(query);
	MYSQL_ROW row = mysql_fetch_row(rezultat);

	check(row != NULL, "Nije moguce zakljuciti ocenu");
	
	int prosek = round(atof(row[0]));
	mysql_free_result(rezultat);

	sprintf(query, "insert into  Zakljucna values(%d, %d, %d)", id, id_predmeta, prosek);
	
	executeQuery(query);
	printf("%s\n", query);
	printf("Uspesno ste zakljucili ocenu\n");
	prikazi_ucenika(id, connection);


}

