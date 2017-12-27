#include  "srednja_skola.h"

void predmeti(MYSQL* connection){
	int option;
	zaglavlje("PREDMETI");


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Pregledaj o predmete\n");
	  	printf("2.Dodaj predmet\n");

	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 3 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	switch (option) {
	    case 1:
	      pretrazi_predmete(connection);
	      break;
	    case 2:
	      dodaj_predmet(connection);
	      break;
	    
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
    
	}

}

void pretrazi_predmete(MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select id, naziv from Predmet order by naziv");
	rezultat = executeQuery(query);
	print(rezultat);

	printf("Unesite id predmeta o kome zelite da vidite detalje\n");
	int id;
	scanf("%d", &id);

	prikazi_predmet(id, connection);

}

void prikazi_predmet(int id, MYSQL* connection){
	zaglavlje("DETALJI PREDMETA");
	MYSQL_RES* rezultat;
	sprintf(query, "select * from Predmet where id=%d", id);
	rezultat = executeQuery(query);
	print(rezultat);

	podkategorija("NASTAVNICI");
	sprintf(query, "select Nastavnik.ime, Nastavnik.prezime from Predaje join Nastavnik on Predaje.id_Nastavnika = Nastavnik.id\
			 		where Predaje.id_predmeta = %d", id);
	rezultat = executeQuery(query);
	print(rezultat);

	int option;
	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Dodelite nastavnika predmetu\n");
		printf("2. Za povratak nazad\n");
		printf("3.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 3 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	switch(option){
		case 1:
	      dodeli_nastavnika(id, connection);	
	      break;
	    
	    case 2:
	      predmeti(connection);
	      break;
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
	}

}

void dodeli_nastavnika(int id, MYSQL* connection){
	MYSQL_RES* rezultat;
	sprintf(query, "select * from Nastavnik  order by prezime");
	rezultat = executeQuery(query);
	print(rezultat);
	int id_nastavnika;
	printf("Unesite id nastavnika koga zelite da dodelite predmetu:\n");
	scanf("%d", &id_nastavnika);

	sprintf(query, "select * from Odeljenje");
	rezultat = executeQuery(query);
	print(rezultat);
	int id_odeljenja;
	printf("Unesite id odeljenja koga zelite da dodelite predmetu:\n");
	scanf("%d", &id_odeljenja);

	sprintf(query, "insert into Predaje values (%d, %d, %d)", id_nastavnika, id, id_odeljenja);
	executeQuery(query);

	printf("Uspesno ste dodelili nastavnika\n");
	prikazi_predmet(id, connection);


}
void dodaj_predmet(MYSQL* connection){
	//MYSQL_RES* rezultat;
	zaglavlje("DODAVANJE PREDMETA");
	
	int id;
	char naziv[BUFFER_SIZE], opis[266];
	

	printf("Unesite id predmeta\n");
	scanf("%d", &id);
	printf("Unesite naziv predmeta\n");
	scanf("%s", naziv);
	printf("Unesite opis predmeta\n");
	scanf(" %[^\n]",opis);
	



	sprintf(query, "insert into Predmet values (%d, \'%s\',\'%s\')",\
			id, naziv, opis);
	executeQuery(query);

	printf("Uspesno ste dodali predmet\n");
	prikazi_predmet(id, connection);
}