#include "srednja_skola.h"

int main(int argc, char **argv)
{
	
	connection =  mysql_init(NULL);

	check(mysql_real_connect(connection, "localhost", "root", "3458rade", "Srednja_skola",0, NULL, 0), mysql_error(connection));
	
	int option;


	do
	{
		printf("Izaberite opciju:\n");

	  	printf("1.Podaci o ucenicima\n");
	  	printf("2.Podaci o profesoria\n");
	  	printf("3.Podaci o predmetima\n");
	  	printf("4.Podaci o odeljenjima\n");
	  	printf("5.Podaci o smerovima\n");
	  	printf("6. Unos i izmena ocena\n");

	  	printf("6.Kraj\n");

	  	scanf("%d", &option);

	  	if (option > 6 || option <1)
	  		printf("\n\nNekorektno odabrana opcija. Molimo pokusajte ponovo.\n\n");

	}while(option > 6 || option < 1);

	switch (option) {
    case 1:
      ucenici(connection);
      break;
    case 2:
     // profesori(connection);
      break;
    case 3:
      //predmeti(connection);
      break;
    case 4:
      //odeljenja(connection);
      break;
    case 5:
      //smerovi(connection);
      break;
    case 6:
      exit(EXIT_SUCCESS);
      break;
  }
  

  mysql_close(connection);

  exit(EXIT_SUCCESS);



	return 0;
}

void errorFatal(const char* msg,const char* fileName,const int lineNumber)
{
	perror(msg);
	fprintf(stderr,"File name:%s\nLine number: %d\n",fileName,lineNumber);
    exit(EXIT_FAILURE);
}

void print(MYSQL_RES* result)
{

  MYSQL_ROW row;
  MYSQL_FIELD *field;

  field = mysql_fetch_field(result);

  int numOfField = mysql_num_fields(result);

  printf("*************************************************\n");
  while((row = mysql_fetch_row(result))!=NULL){
    for(int i=0;i<numOfField;++i){
      printf("%*s:\t%s\n",-25,field[i].name,row[i]);
    }
    printf("------------------------------------------------\n");
  }
  printf("*************************************************\n");

  mysql_free_result(result);
}

MYSQL_RES* executeQuery(char* query)
{
  check(mysql_query(connection,query)==0,\
          mysql_error(connection));
  MYSQL_RES *result = mysql_use_result(connection);
  return result;
}

void zaglavlje(char* nsalov){
	printf("\n\n************************************************************\n");
	printf("%35s\n", nsalov );
	printf("************************************************************\n\n");
}

void podkategorija(char* naslov){
	{
	printf("\n------------------- %s ---------------------\n\n", naslov);
}
}

