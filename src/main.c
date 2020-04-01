#include <stdlib.h>

#include "define.h"
#include "struct.h"
#include "init.h"
#include "display.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    Characters *pCharacters = calloc(1,sizeof(Characters));
    if(pCharacters == NULL){
        printfflush("ERROR : pCharacters creation failed \n");
        exit(EXIT_FAILURE);
    }
	
    int launched = 1;

    int choix = 0;

// Refaire le menu

    do{
        printfflush("Menu :\n");
        printfflush("1) Nouveau Personnage\n");
        printfflush("2) Copy dans un fichier\n");
        printfflush("3) Quitter\t");
        scanf("%d",&choix);
        if(choix == 1){
            system("clear");    
            Init(pCharacters);
            displayCharacters(pCharacters);
        }
        else if(choix == 2){
            Init(pCharacters);
            displayCharactersFiles(pCharacters);
        }
        else
            launched = 0;
    }while(launched == 1);
	
	freeStructCharacters(pCharacters);
	return 0;
}

/*
	faire :
		- doubler les tab de RandomName 

		- pensé  Don ? // affichage avant
*/