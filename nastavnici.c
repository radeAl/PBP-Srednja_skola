#include "srednja_skola.h"

void nastavnici(MYSQL* connection){
	int option;
	zaglavlje("NASTAVNICI");


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Pregledaj o profesore\n");
	  	printf("2.Dodaj nastavnika\n");
	  	
	  	
	  	printf("3.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 3 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 3 || option < 1);

	switch (option) {
	    case 1:
	      pretrazi_nastavnika(connection);
	      break;
	    case 2:
	      dodaj_nastavnika(connection);
	      break;
	    
	    
	    case 3:
	      exit(EXIT_SUCCESS);
	      break;
    
	}

}

void pretrazi_nastavnika(MYSQL* connection){
	zaglavlje("PRETRAGA NASTAVNIKA");

	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE];
	printf("Unesite ime nastavnika\n");
	scanf("%s", ime);
	printf("Unesite prezime nastavnika\n");
	scanf("%s", prezime);

	sprintf(query, "select * from Nastavnik where ime=\'%s\' and prezime = \'%s\'", ime, prezime);
	MYSQL_RES *rezultat = executeQuery(query);
	print(rezultat);

	int option;

	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za dedatalje o nastavniku\n");
		printf("2. Za izmenu nastavnika\n");
		printf("3. Za povratak nazad\n");

	  	
	  	printf("4.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 4 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 4 || option < 1);

	int id;

	switch(option){
		case 1:
	      printf("Unesite id Nastavnika za koga zelite detalje\n");
	      
	      scanf("%d", &id);
	      prikazi_nastavnika(id, connection);
	      break;
	   
	    case 2:
	    	printf("Unesite id nastavnika  koga zelite da izmenite\n");
	      
	      	scanf("%d", &id);
	    	izmeni_nastavnika(id, connection);
	    	break;
	    case 3:
	    	nastavnici(connection);
	    	break;
	    
	    case 4:
	      exit(EXIT_SUCCESS);
	      break;
	}

}
void prikazi_nastavnika(int id, MYSQL* connection){
	zaglavlje("DETALJI O NASTAVNIKU");
	sprintf(query, "select * from Nastavnik where  id = %d", id);

	MYSQL_RES *rezultat = executeQuery(query);
	print(rezultat);

	podkategorija("PREDAJE");
	sprintf(query, "select Predmet.naziv, Odeljenje.naziv as \'Naziv odeljenje\', Odeljenje.godina from\
					Predmet join Predaje on Predmet.id = Predaje.id_predmeta\
					join Odeljenje on Odeljenje.id=Predaje.id_odeljenja\
					where Predaje.id_nastavnika=%d", id);
	
	rezultat = executeQuery(query);
	print(rezultat);


}
void dodaj_nastavnika(MYSQL* connection){
	
	//MYSQL_RES* rezultat;
	zaglavlje("DODAVANJE NASTAVNIKA");
	
	int id;
	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE], zvanje[BUFFER_SIZE];
	

	printf("Unesite id(jmbg) nastavnika\n");
	scanf("%d", &id);
	printf("Unesite ime nastavnika\n");
	scanf("%s", ime);
	printf("Unesite prezime nastavnika\n");
	scanf("%s", prezime);
	
	printf("Unesite zvanje nastavnika\n");
	scanf("%s", zvanje);
	


	sprintf(query, "insert into Nastavnik values (%d, \'%s\',\'%s\', \'%s\')",\
			id, ime, prezime, zvanje);
	executeQuery(query);

	printf("Uspesno ste dodali nastavnika\n");
	prikazi_nastavnika(id, connection);
}
void izmeni_nastavnika(int id, MYSQL* connection){
	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE], zvanje[BUFFER_SIZE];

	podkategorija("IZMENA OSNOVNIH PODATAKA");

	printf("Unesite novo ime nastavnika\n");
	scanf("%s", ime);
	printf("Unesite novo prezime nastavnika\n");
	scanf("%s", prezime);
	printf("Unesite novi zvanje nastavnika\n");
	scanf("%s", zvanje);
	

	sprintf(query, "update Nastavnik  set ime=\'%s\', prezime=\'%s\', zvanje=\'%s\'\
					where id=%d", ime, prezime, zvanje, id);
	//printf("%s\n", query);
	executeQuery(query);

	printf("Uneti podaci su uspeno izmenjeni\n");

}


