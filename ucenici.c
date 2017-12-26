#include "srednja_skola.h"

void ucenici(MYSQL* connection){
	int option;
	zaglavlje("UCENICI");


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Pregledaj o ucenika\n");
	  	printf("2.Dodaj ucenika\n");
	  	printf("3.Izbrisi ucenika\n");
	  	printf("4.Izmeni ucenika\n");
	  	
	  	printf("5.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 5 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 6 || option < 1);

	switch (option) {
	    case 1:
	      pretrazi_ucenika(connection);
	      break;
	    case 2:
	      dodaj_ucenika(connection);
	      break;
	    case 3:
	      pretrazi_ucenika(connection);
	      break;
	    case 4:
	      pretrazi_ucenika(connection);
	      break;
	    
	    case 5:
	      exit(EXIT_SUCCESS);
	      break;
    
	}

}

void pretrazi_ucenika(MYSQL* connection){
	zaglavlje("PRETRAGA UCENIKA");

	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE];
	printf("Unesite ime ucenika\n");
	scanf("%s", ime);
	printf("Unesite prezime ucenika\n");
	scanf("%s", prezime);

	sprintf(query, "select * from Ucenik where ime=\'%s\' and prezime = \'%s\'", ime, prezime);
	MYSQL_RES *rezultat = executeQuery(query);
	print(rezultat);

	int option;

	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za dedatalje o uceniku\n");
		printf("2. Za brisanje  ucenika\n");
		printf("3. Za izmenu ucenika\n");
		printf("4. Za povratak nazad\n");

	  	
	  	printf("5.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 5 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 5 || option < 1);

	int id;

	switch(option){
		case 1:
	      printf("Unesite id studenta za koga zelite detalje\n");
	      
	      scanf("%d", &id);
	      prikazi_ucenika(id, connection);
	      break;
	    case 2:
	      printf("Unesite id studenta  koga zelite da obrisete\n");
	      
	      scanf("%d", &id);
	      ukloni_ucenika(id, connection);
	      break;
	    case 3:
	    	printf("Unesite id studenta  koga zelite da obrisete\n");
	      
	      	scanf("%d", &id);
	    	izmeni_ucenika(id, connection);
	    	break;
	    case 4:
	    	ucenici(connection);
	    	break;
	    
	    case 5:
	      exit(EXIT_SUCCESS);
	      break;
	}


}


void prikazi_ucenika(int id, MYSQL* connection){
	zaglavlje("PODACI O STUDENTU");
	podkategorija("PODACI PODACI");
	sprintf(query, "select 	Ucenik.ime, Ucenik.prezime, Ucenik.mesto_rodjenja, Ucenik.datum_rodjenja, Ucenik.adresa,\
							Ucenik.prosek, Odeljenje.godina, Odeljenje.naziv  as \'Odeljenje\',Smer.naziv as \'Smer\', Status.naziv as \'Status\'\
							,Nastavnik.ime as \'Ime razrednog\', Nastavnik.prezime as \'Prezime razrednog\'\
							from 	Ucenik join Odeljenje on Ucenik.id_odeljenja = Odeljenje.id\
									join Smer on Smer.id = Odeljenje.id_smera\
									join Nastavnik on Nastavnik.id = Odeljenje.id_razrednog\
									join Status on Ucenik.id_status = Status.id\
							where Ucenik.id = %d", id);
	MYSQL_RES* rezultat = executeQuery(query);
	
	print(rezultat);

	podkategorija("STARATELJI");
	sprintf(query, "select Staratelj.ime, Staratelj.prezime \
					from Ucenik_Staratelj join Staratelj on Ucenik_Staratelj.id_staratelja = Staratelj.id\
					where Ucenik_Staratelj.id_ucenika = %d", id);
	rezultat = executeQuery(query);
	print(rezultat);

	podkategorija("OCENE");

	sprintf(query, "select Ocena.id_predmeta,Predmet.naziv, Ocena.ocena\
					from Ocena join Predmet on Ocena.id_predmeta = Predmet.id\
					where Ocena.id_ucenika = %d and Ocena.id_predmeta in (select Smer_Predmet.id_predmeta\
							from Smer_Predmet join Odeljenje on Odeljenje.id_smera = Smer_Predmet.id_smera\
							where Smer_Predmet.godina = Odeljenje.godina)", id);

	rezultat = executeQuery(query);
	
	//print(rezultat);

	MYSQL_ROW row;
	//MYSQL_FIELD *field;

	  //field = mysql_fetch_field(result);

	  //nt numOfField = mysql_num_fields(result);

	Ocene o[BUFFER_SIZE];
	int i = 0;
	//print(rezultat);
	printf("*************************************************\n");
	while((row = mysql_fetch_row(rezultat))!=NULL){
		
	  	int id_predmeta = atoi(row[0]);
	  	
	  	
	  	
	  	int ind = 1;

	  	for (int j = 0; j < i; ++j)
	  	{
	  		if (o[j].id_predmeta == id_predmeta){
	  			ind = 0;
	  			o[j].ocena[o[j].broj_ocena] = atoi(row[2]);
	  			o[j].broj_ocena++;
	  			break;
	  		}
	  	}

	  	if (ind == 1)
	  	{	o[i].id_predmeta = id_predmeta;
	  		//o[i].naziv = row[1];

	  		sprintf(o[i].naziv, "%s", row[1]);
	  		o[i].ocena[0]= atoi(row[2]);
	  		o[i].broj_ocena = 1;
	  		i++;
	  	}



	  	
	}

	for (int j = 0; j < i; ++j)
	{
		printf("%s\n", o[j].naziv);
		for (int k = 0; k < o[j].broj_ocena; ++k)
		{	
			printf("%2d ", o[j].ocena[k] );
		}
		printf("\n");
	}

	printf("*************************************************\n");

	
	podkategorija("ZAKLJUCENE");
	sprintf(query, "select Predmet.naziv , Zakljucna.ocena from \
					Zakljucna join Predmet on Zakljucna.id_predmeta = Predmet.id\
					where Zakljucna.id_ucenika= %d", id);
	rezultat = executeQuery(query);
	print(rezultat);

	podkategorija("IZOSTANCI");
	sprintf(query, "select 	sum(case when opravdano = TRUE then broj_casova else 0 end) as \'Opravdano\',\
							sum(case when opravdano = FALSE then broj_casova else 0 end) as \'Neopravdano\'\
							from Izostanci  where id_ucenika = %d", id);
	//printf("%s\n",query );
	executeQuery(query);
	print(rezultat);
			


}

void dodaj_ucenika(MYSQL* connection){
	MYSQL_RES* rezultat;
	float prosek = 0;
	int id, id_status, id_odeljenja, id_staratelja;
	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE], adresa[BUFFER_SIZE], datum_rodjenja[BUFFER_SIZE], mesto_rodjenja[BUFFER_SIZE];
	char ime_staratela[BUFFER_SIZE], prezime_staratelja[BUFFER_SIZE], broj_telefona[BUFFER_SIZE];

	printf("Unesite id(jmbg) ucenika\n");
	scanf("%d", &id);
	printf("Unesite ime ucenika\n");
	scanf("%s", ime);
	printf("Unesite prezime ucenika\n");
	scanf("%s", prezime);
	printf("Unesite datum rodjenja ucenika\n");
	scanf("%s", datum_rodjenja);
	printf("Unesite mesto_rodjenja ucenika\n");
	scanf("%s", mesto_rodjenja);
	printf("Unesite adresu ucenika\n");
	scanf("%s", adresa);
	
	sprintf(query, "select id, naziv from Status");
	rezultat = executeQuery(query);

	print(rezultat);

	printf("Unesite id zeljenog statusa iz prethodne liste\n");
	scanf("%d", &id_status);

	sprintf(query, "select id, naziv, godina from Odeljenje");
	rezultat = executeQuery(query);

	print(rezultat);

	printf("Unesite id zeljenog odeljnjea iz prethodne liste\n");
	scanf("%d", &id_odeljenja);

	sprintf(query, "insert into Ucenik values (%d, \'%s\',\'%s\', \'%s\', \'%s\', \'%s\', %f, %d,%d)",\
			id, ime, prezime, mesto_rodjenja, datum_rodjenja, adresa, prosek, id_status,id_odeljenja);
			//(3, 'Ivana', 'Djukic', 'Beograd', '2001-11-12', 'PEtra Kocica 32',0, 1, 3),
			//(13, 'Ivana', 'Djukic', 'Beograd', '2001-11-12', 'PEtra Kocica 32',0, 1, 3)
	printf("%s\n", query);
	rezultat = executeQuery(query);

	podkategorija("UNOS STARTELJA");


	printf("Izaberite opciju:\n");

	printf("1.Postojeci Staratelj\n");
	printf("2.Novi Staratelj\n");

	int option;
	scanf("%d", &option);

	

	if(option == 1){
		sprintf(query, "select id, ime, prezime from Staratelj");
		rezultat = executeQuery(query);
		print(rezultat);

		printf("Unesite id zeljenjog staratelja iz prethodne liste\n");
		scanf("%d", &id_staratelja);
	}
	else if (option == 2){

		printf("Unesite id(jmbg) staratelja\n");
		scanf("%d", &id_staratelja);

		printf("Unesite ime staratelja\n");
		scanf("%s", ime_staratela);

		printf("Unesite prezime staratelja\n");
		scanf("%s", prezime_staratelja);

		printf("Unesite broj telefona staratelja\n");
		scanf("%s", broj_telefona);

		sprintf(query, "insert into Staratelj value (%d, \'%s\', \'%s\', \'%s\')", id_staratelja, ime_staratela, prezime_staratelja, broj_telefona);
		executeQuery(query);

	}

	sprintf(query, "insert into Ucenik_Staratelj values(%d, %d)", id, id_staratelja);
	executeQuery(query);

	printf("Uspesno ste uneli ucenika:\n");
	prikazi_ucenika(id, connection);
}

void ukloni_ucenika(int id, MYSQL* connection){
	sprintf(query, "delete from Ucenik where id=%d", id);
	printf("%s\n", query);
	//executeQuery(query);
	printf("Uspesno ste obrisali ucenika");
	int option;
	do
	{
		printf("\nIzaberite opciju:\n" );
		printf("1. Za povratak nazad\n");
		printf("2.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 2 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 2 || option < 1);

	switch(option){
		case 1:
	      ucenici(connection);	
	      break;
	    
	    case 2:
	      exit(EXIT_SUCCESS);
	      break;
	}


}

void izmeni_ucenika(int id, MYSQL* connection){
	int option;
	do
	{	zaglavlje("IZMENA UCENIKA");
		printf("\nIzaberite opciju:\n" );
		printf("1. Izmeniti osnovne podatke\n");
		printf("2.	Izmeniti staratelja \n");
		printf("3. Promeniti status\n");
		printf("4. Promeniti odeljenje\n");
		printf("5. Nazad\n");
		printf("6. Kraj\n");
	  	
	  	scanf("%d", &option);

	  	if (option > 6 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 6 || option < 1);

	switch(option){
		case 1:
	      izmeni_osnovne_podatke(id, connection);	
	      break;
	    case 2:
	      izmeni_staratelja(id, connection);	
	      break;
	    case 3:
	      promeni_status(id, connection);	
	      break;
	    case 4:
	      promeni_odeljenje(id, connection);	
	      break;
	    case 5:
	      ucenici(connection);	
	      break;
	    
	    case 6:
	      exit(EXIT_SUCCESS);
	      break;
	}

}


void izmeni_osnovne_podatke(int id, MYSQL* connection)
{
	char ime[BUFFER_SIZE], prezime[BUFFER_SIZE], adresa[BUFFER_SIZE], datum_rodjenja[BUFFER_SIZE], mesto_rodjenja[BUFFER_SIZE];

	podkategorija("IZMENA OSNOVNIH PODATAKA");

	printf("Unesite novo ime ucenika\n");
	scanf("%s", ime);
	printf("Unesite novo prezime ucenika\n");
	scanf("%s", prezime);
	printf("Unesite novi datum rodjenja ucenika\n");
	scanf("%s", datum_rodjenja);
	printf("Unesite novo mesto_rodjenja ucenika\n");
	scanf("%s", mesto_rodjenja);
	printf("Unesite novu adresu ucenika\n");
	scanf("%s", adresa);

	sprintf(query, "update Ucenik  set ime=\'%s\', prezime=\'%s\', datum_rodjenja=\'%s\',\
					mesto_rodjenja=\'%s\', adresa=\'%s\' where id=%d", ime, prezime, datum_rodjenja, mesto_rodjenja, adresa, id);
	executeQuery(query);

	printf("Uneti podaci su uspeno izmenjeni\n");
	
}
void izmeni_staratelja(int id, MYSQL* connection){
	podkategorija("IZMENA STARTELJA");


	printf("Izaberite opciju:\n");

	printf("1.Izmeni postojeci Staratelj\n");
	printf("2.Dodaj novog staratelj\n");

	int option;
	scanf("%d", &option);

	MYSQL_RES* rezultat;
	int id_staratelja;
	char ime_staratela[BUFFER_SIZE], prezime_staratelja[BUFFER_SIZE], broj_telefona[BUFFER_SIZE]; 

	if(option == 1){

		sprintf(query, "select id, ime, prezime from\
						Staratelj join Ucenik_Staratelj on Ucenik_Staratelj.id_staratelja = Staratelj.id\
						where Ucenik_Staratelj.id_ucenika=%d", id);
		rezultat = executeQuery(query);
		print(rezultat);

		printf("Unesite id zeljenjog staratelja iz prethodne liste\n");
		scanf("%d", &id_staratelja);

		printf("Unesite novo ime staratelja\n");
		scanf("%s", ime_staratela);
		printf("Unesite novo prezime staratelja\n");
		scanf("%s", prezime_staratelja);
		printf("Unesite novi broj telefona staratelja\n");
		scanf("%s", broj_telefona);

		sprintf(query, "update Staratelj set ime=\'%s\', prezime=\'%s\', telefon=\'%s\' where id=%d",
				ime_staratela, prezime_staratelja, broj_telefona, id_staratelja);
		printf("%s\n",query );
		executeQuery(query);

		printf("Uspesno ste napravili izmene\n");
		

	}
	else if (option == 2){

		printf("Unesite id(jmbg) staratelja\n");
		scanf("%d", &id_staratelja);

		printf("Unesite ime staratelja\n");
		scanf("%s", ime_staratela);

		printf("Unesite prezime staratelja\n");
		scanf("%s", prezime_staratelja);

		printf("Unesite broj telefona staratelja\n");
		scanf("%s", broj_telefona);

		sprintf(query, "insert into Staratelj value (%d, \'%s\', \'%s\', \'%s\')", id_staratelja, ime_staratela, prezime_staratelja, broj_telefona);
		executeQuery(query);

		sprintf(query, "insert into Ucenik_Staratelj values(%d, %d)", id, id_staratelja);
		executeQuery(query);

		printf("Uspesno ste uneli staratelja\n");
	}
	prikazi_ucenika(id, connection);


}


	
void promeni_status(int id, MYSQL* connection){
	MYSQL_RES* rezultat;
	podkategorija("PROMENA STATUSA");
	sprintf(query, "select * from Status");
	rezultat = executeQuery(query);
	print(rezultat);

	printf("Izaberite id statusa koji zelite da odelite studentu\n");
	int id_status;
	scanf("%d", &id_status);

	sprintf(query, "update Ucenik set id_status=%d where id=%d", id_status, id);
	executeQuery(query);
	printf("Uspesno ste izmenili status\n");

	prikazi_ucenika(id, connection);

}
void promeni_odeljenje(int id, MYSQL* connection){
	MYSQL_RES* rezultat;
	podkategorija("PROMENA ODELJENJA");
	sprintf(query, "select * from Odeljenje");
	rezultat = executeQuery(query);
	print(rezultat);

	printf("Izaberite id statusa koji zelite da dodelite studentu\n");
	int id_odeljenja;
	scanf("%d", &id_odeljenja);

	sprintf(query, "update Ucenik set id_odeljenja=%d where id=%d", id_odeljenja, id);
	executeQuery(query);
	printf("Uspesno ste izmenili odeljenje\n");

	prikazi_ucenika(id, connection);
}