#include "srednja_skola.h"

void smerovi(MYSQL* connection){
	int option;
	zaglavlje("SMEROVI");


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Pregledaj smer\n");
	  	printf("2.Dodaj smer\n");
	  
	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 3 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	switch (option) {
	    case 1:
	      pretrazi_smerove(connection);
	      break;
	    case 2:
	      dodaj_smer(connection);
	      break;
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
    
	}

}

	
void pretrazi_smerove(MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select * from Smer");
	rezultat = executeQuery(query);
	print(rezultat);

	int option;

	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za dedatalje o smeru\n");
		printf("2. Za nazad\n");

	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	if (option > 3 || option <1)
	  	printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	int id;

	switch(option){
		case 1:
	      printf("Unesite id smera za koga zelite detalje\n");
	      
	      scanf("%d", &id);
	      prikazi_smer(id, connection);
	      break;
	    case 2:
	     	smerovi(connection);
	      break;
	    
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
	}

}
void prikazi_smer(int id, MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select * from Smer where id=%d", id);
	rezultat = executeQuery(query);
	print(rezultat);

	podkategorija("PREDMETI");
	sprintf(query, "select Predmet.id, Predmet.naziv, Smer_Predmet.godina from \
					Predmet join Smer_Predmet on Predmet.id = Smer_Predmet.id_predmeta\
					where Smer_Predmet.id_smera=%d order by Smer_Predmet.godina", id);
	rezultat=executeQuery(query);
	print(rezultat);

	int option;

	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za dodavanje predmeta smeru\n");
		printf("2. Za nazad\n");

	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	if (option > 3 || option <1)
	  	printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	

	switch(option){
		case 1:

	      dodaj_smeru_predmet(id, connection);
	      break;
	    case 2:
	     	smerovi(connection);
	      break;
	    
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
	}

}
void dodaj_smeru_predmet(int id, MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select * from Predmet\
					where Predmet.id not in \
							(select Smer_Predmet.id_predmeta from Smer_Predmet where Smer_Predmet.id_smera =%d)", id);
	rezultat = executeQuery(query);
	print(rezultat);
	int id_predmeta;
	printf("Unesite id predmeta iz prethodne liste koji zelite da dodate smeru\n");
	scanf("%d", &id_predmeta);

	int godina;
	printf("Unesite godina na kojoj ce se slusati taj predmet\n");
	scanf("%d", &godina);


	sprintf(query, "insert into Smer_Predmet values (%d, %d, %d)", id, id_predmeta, godina);
	printf("%s\n",query );
	executeQuery(query);
	printf("Uspesno ste dodali predmet\n");
	prikazi_smer(id, connection);
}
void dodaj_smer(MYSQL* connection){
	zaglavlje("DODAVANJE SMERA");
	
	int id;
	char naziv[BUFFER_SIZE], opis[266], zvanje[BUFFER_SIZE];
	

	printf("Unesite id smera\n");
	scanf("%d", &id);
	printf("Unesite naziv smera\n");
	scanf("%s", naziv);
	printf("Unesite opis predmeta\n");
	scanf(" %[^\n]",opis);
	printf("Unesite Zvanje koje se dobija\n");
	
	scanf(" %[^\n]",zvanje);



	sprintf(query, "insert into Smer values (%d, \'%s\',\'%s\',\'%s\')",\
			id, naziv, opis, zvanje);
	executeQuery(query);

	printf("Uspesno ste dodali smer\n");
	prikazi_smer(id, connection);	
}