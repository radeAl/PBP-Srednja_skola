#include "srednja_skola.h"

void odeljenja(MYSQL* connection){
	int option;
	zaglavlje("SMEROVI");


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Pregledaj odeljenja\n");
	  	printf("2.Dodaj odeljenje\n");
	  
	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 3 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	switch (option) {
	    case 1:
	      pretrazi_odeljenja(connection);
	      break;
	    case 2:
	      dodaj_odeljenje(connection);
	      break;
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
    
	}
}

void pretrazi_odeljenja(MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select * from Odeljenje");
	rezultat = executeQuery(query);
	print(rezultat);

	int option;

	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za dedatalje o odeljnju\n");
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
	      prikazi_odeljenje(id, connection);
	      break;
	    case 2:
	     	odeljenja(connection);
	      break;
	    
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
	}

}

void prikazi_odeljenje(int id, MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select Odeljenje.id, Odeljenje.naziv, Odeljenje.godina, Smer.naziv \'Smer\',\
					Nastavnik.ime as \'Ime Razrednog\', Nastavnik.prezime as \'Prezime razrednog\' from\
					Odeljenje join Smer on Odeljenje.id_smera = Smer.id\
					join Nastavnik on Odeljenje.id_razrednog = Nastavnik.id\
					where Odeljenje.id=%d", id);
	rezultat = executeQuery(query);
	print(rezultat);

	podkategorija("UCENICI");
	sprintf(query, "select ime, prezime from Ucenik where id_odeljenja = %d", id);
	rezultat=executeQuery(query);
	print(rezultat);

	int option;

	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za promenu razrednog\n");
		printf("2. Za nazad\n");

	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	if (option > 3 || option <1)
	  	printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	

	switch(option){
		case 1:

	      promeni_razrednog(id, connection);
	      break;
	    case 2:
	     	odeljenja(connection);
	      break;
	    
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
	}
}
void promeni_razrednog(int id, MYSQL* connection){
	int id_razrednog;
	printf("Unesite id profesora koga zelite da postavite na razrednog:\n");
	scanf("%d", &id_razrednog);

	sprintf(query, "update Odeljenje set id_razrednog = %d where id= %d", id_razrednog, id);
	executeQuery(query);

	printf("Uspesno ste promenili razrednog\n");
	prikazi_odeljenje(id, connection);


}
void dodaj_odeljenje(MYSQL* connection){
	zaglavlje("DODAVANJE ODELJENJA");
	
	int id, godina = 1, id_razrednog, id_smera;
	char naziv[BUFFER_SIZE];
	

	printf("Unesite id odeljnja\n");
	scanf("%d", &id);
	printf("Unesite naziv odeljjea\n");
	scanf("%s", naziv);
	printf("Unesite id razrednog profesora\n");
	scanf("%d", &id_razrednog);
	printf("Unesite id smera\n");
	scanf("%d", &id_smera);
	


	sprintf(query, "insert into Odeljenje values (%d, \'%s\',%d,%d, %d)",\
			id, naziv,godina, id_razrednog, id_smera);
	executeQuery(query);

	printf("Uspesno ste dodali odeljenje\n");
	prikazi_odeljenje(id, connection);
}