#include <stdlib.h>

#include "define.h"
#include "struct.h"
#include "init.h"
#include "display.h"

void printfflush(char *);

int main(int argc, char const *argv[])
{
	system("clear");
	int launched = 1;
	Characters *pCharacters = calloc(1,sizeof(Characters));
	if(pCharacters == NULL){
		fprintf(stderr, "ERROR : pCharacters creation failed.\n");
        exit(EXIT_FAILURE);
	}
	do{
		printfflush("MENU :\n\n");
		printfflush("1)\tNouveau Personnage\n");
		printfflush("2)\tCopier Personnage dans un fichier\n");
		printfflush("3)\tQuitter\n");
		printfflush("Entrée un chiffre\t");
		int cmd;
		scanf("%d",&cmd);
		if(cmd == 3)
			launched = 0;
		else if(cmd == 1){
		//	freeStruct(pCharacters);
			system("clear");
			Init(pCharacters);
			displayCharacters(pCharacters);
			printfflush("\n");
		}
		else if(cmd == 2){
			displayCharactersFiles(pCharacters);
			system("clear");
			printfflush("copy effectuée !\n\n");
			freeStruct(pCharacters);
		}else
			break;
	}while(launched);
	freeStruct(pCharacters);
	return 0;
}

void printfflush(char *s){
	printf("%s", s);fflush(stdout);
}

/*
	faire :
		- pensé  Don ?
*/