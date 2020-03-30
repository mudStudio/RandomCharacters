#include "display.h"

void displayCharacters(Characters *pCharacters){
	printf("Affichage du Personnage :\n");fflush(stdout);
	printf("\n\t\tNom :\t%s\t\tSex :\t%s\n\n",pCharacters->nameCharacters, pCharacters->pAttributs->Sex);fflush(stdout);
	printf("Attributs du Personnage :\n\n");fflush(stdout);
	displayAttributs(pCharacters);
	printf("\nCompétences du Personnage :");fflush(stdout);
	displayCompetences(pCharacters);
	printf("\nDon du Personnage :\n");fflush(stdout);
	displayDon(pCharacters);
}

void displayAttributs(Characters *pCharacters){
	printf("\tForce = %d\t\t\tBonusForce = %d\n", pCharacters->pAttributs->tabAttributs[0], pCharacters->pAttributs->Bonustab[0]);fflush(stdout);
	printf("\tDexterite = %d\t\t\tBonusDexterite = %d\n", pCharacters->pAttributs->tabAttributs[1], pCharacters->pAttributs->Bonustab[1]);fflush(stdout);
	printf("\tConstitution = %d\t\tBonusConstitution = %d\n", pCharacters->pAttributs->tabAttributs[2], pCharacters->pAttributs->Bonustab[2]);fflush(stdout);
	printf("\tInteligence = %d\t\tBonusInteligence = %d\n", pCharacters->pAttributs->tabAttributs[3], pCharacters->pAttributs->Bonustab[3]);fflush(stdout);
	printf("\tSagesse = %d\t\t\tBonusSagesse = %d\n", pCharacters->pAttributs->tabAttributs[4], pCharacters->pAttributs->Bonustab[4]);fflush(stdout);
	printf("\tCharisme = %d\t\t\tBonusCharisme = %d\n\n", pCharacters->pAttributs->tabAttributs[5], pCharacters->pAttributs->Bonustab[5]);fflush(stdout);
	printf("\tChance = %d\t\t\tBonusChance = %d\n\n", pCharacters->pAttributs->tabAttributs[6], pCharacters->pAttributs->Bonustab[6]);fflush(stdout);
}

void displayCompetences(Characters *pCharacters){
	printf("\tCompétences\t+\tBonus d'Attribut\t=\tTotal\n\n"); fflush(stdout);
	printf("\tInformatique\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[0], pCharacters->pAttributs->Bonustab[3],\
pCharacters->pCompetences->tabCompetence[0] + pCharacters->pAttributs->Bonustab[3]);fflush(stdout);
	printf("\tDémolition\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[1], pCharacters->pAttributs->Bonustab[3],\
pCharacters->pCompetences->tabCompetence[1] + pCharacters->pAttributs->Bonustab[3] );fflush(stdout);
	printf("\tDiscrétion\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[2], pCharacters->pAttributs->Bonustab[1],\
pCharacters->pCompetences->tabCompetence[2] + pCharacters->pAttributs->Bonustab[1]);fflush(stdout);
	printf("\tVigilance\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[3], pCharacters->pAttributs->Bonustab[4],\
pCharacters->pCompetences->tabCompetence[3] + pCharacters->pAttributs->Bonustab[4] );fflush(stdout);
	printf("\tPersuasion\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[4], pCharacters->pAttributs->Bonustab[5],\
pCharacters->pCompetences->tabCompetence[4] + pCharacters->pAttributs->Bonustab[5] );fflush(stdout);
	printf("\tRéparation\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[5], pCharacters->pAttributs->Bonustab[3],\
pCharacters->pCompetences->tabCompetence[5] + pCharacters->pAttributs->Bonustab[3] );fflush(stdout);
	printf("\tSécurité\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[6], pCharacters->pAttributs->Bonustab[4],\
pCharacters->pCompetences->tabCompetence[6] + pCharacters->pAttributs->Bonustab[4]);fflush(stdout);
	printf("\tPremierSecours\t:\t%d\t+\t%d\t=\t%d\n", pCharacters->pCompetences->tabCompetence[7], pCharacters->pAttributs->Bonustab[4],\
pCharacters->pCompetences->tabCompetence[7] + pCharacters->pAttributs->Bonustab[4]);fflush(stdout);
}

void displayDon(Characters *pCharacters){
	printf("\tDon en cours de Développement\n\n\tNombre de Don Potentiel :\t%d\n\n", pCharacters->pDon->donPresence);fflush(stdout);
	
	if(pCharacters->pDon->donPresence > 0){
		printf("\t%s\n\n", pCharacters->pDon->plstPerks->namePerks);fflush(stdout);
		printf("Tab de modif d'Attributs : \n\n");fflush(stdout);
		for (int i = 0; i < 7; ++i)
			printf("\t\t ATT : %d\t\t Comp : %d\n", pCharacters->pDon->plstPerks->tabAttPerks[i], pCharacters->pDon->plstPerks->tabCompPerks[i]);
		printf("\n");
		if(pCharacters->pDon->donPresence == 2){
			printf("\t%s\n\n", pCharacters->pDon->plstPerks->next->namePerks);fflush(stdout);
			printf("Tab de modif d'Attributs : \n\n");fflush(stdout);
			for (int i = 0; i < 7; ++i)
				printf("\t\t ATT : %d\t\t Comp : %d\n", pCharacters->pDon->plstPerks->next->tabAttPerks[i], pCharacters->pDon->plstPerks->next->tabCompPerks[i]);
			printf("\n");
		}
	}
	else
		printf("\n");
}

void displayCharactersFiles(Characters *pCharacters){
	
	char *namefiles = "save/";
	namefiles = ft_strjoin(namefiles, pCharacters->nameCharacters);
	namefiles = ft_strjoin(namefiles,".txt");
	FILE *files = fopen(namefiles,"a");

	fprintf(files, "Affichage du Personnage :\n");fflush(files);
	fprintf(files, "\n\t\tNom :\t%s\t\tSex :\t%s\n\n",pCharacters->nameCharacters, pCharacters->pAttributs->Sex);fflush(stdout);
	fprintf(files, "Attributs du Personnage :\n\n");fflush(files);
	displayAttributsFiles(files, pCharacters);
	fprintf(files, "\nCompétences du Personnage :");fflush(files);
	displayCompetencesFiles(files, pCharacters);
	fprintf(files, "\nDon du Personnage :\n");fflush(files);
	displayDonFiles(files, pCharacters);
	fclose(files);
}

void displayAttributsFiles(FILE *files, Characters *pCharacters){
	fprintf(files, "\tForce = %d\t\t\t\tBonusForce = %d\n", pCharacters->pAttributs->tabAttributs[0], pCharacters->pAttributs->Bonustab[0]);fflush(files);
	fprintf(files, "\tDexterite = %d\t\t\tBonusDexterite = %d\n", pCharacters->pAttributs->tabAttributs[1], pCharacters->pAttributs->Bonustab[1]);fflush(files);
	fprintf(files, "\tConstitution = %d\t\tBonusConstitution = %d\n", pCharacters->pAttributs->tabAttributs[2], pCharacters->pAttributs->Bonustab[2]);fflush(files);
	fprintf(files, "\tInteligence = %d\t\tBonusInteligence = %d\n", pCharacters->pAttributs->tabAttributs[3], pCharacters->pAttributs->Bonustab[3]);fflush(files);
	fprintf(files, "\tSagesse = %d\t\t\tBonusSagesse = %d\n", pCharacters->pAttributs->tabAttributs[4], pCharacters->pAttributs->Bonustab[4]);fflush(files);
	fprintf(files, "\tCharisme = %d\t\t\tBonusCharisme = %d\n\n", pCharacters->pAttributs->tabAttributs[5], pCharacters->pAttributs->Bonustab[5]);fflush(files);
	fprintf(files, "\tChance = %d\t\t\tBonusChance = %d\n\n", pCharacters->pAttributs->tabAttributs[6], pCharacters->pAttributs->Bonustab[6]);fflush(files);
}

void displayCompetencesFiles(FILE *files, Characters *pCharacters){
	fprintf(files, "\n\n\t\t\t\t\tCompétences\t\t+\t\tBonus d'Attribut\t=\t\tTotal\n\n"); fflush(files);
	fprintf(files, "Informatique\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[0], pCharacters->pAttributs->Bonustab[3],\
pCharacters->pCompetences->tabCompetence[0] + pCharacters->pAttributs->Bonustab[3]);fflush(files);
	fprintf(files, "Démolition\t\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[1], pCharacters->pAttributs->Bonustab[3],\
pCharacters->pCompetences->tabCompetence[1] + pCharacters->pAttributs->Bonustab[3] );fflush(files);
	fprintf(files, "Discrétion\t\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[2], pCharacters->pAttributs->Bonustab[1],\
pCharacters->pCompetences->tabCompetence[2] + pCharacters->pAttributs->Bonustab[1]);fflush(files);
	fprintf(files, "Vigilance\t\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[3], pCharacters->pAttributs->Bonustab[4],\
pCharacters->pCompetences->tabCompetence[3] + pCharacters->pAttributs->Bonustab[4] );fflush(files);
	fprintf(files, "Persuasion\t\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[4], pCharacters->pAttributs->Bonustab[5],\
pCharacters->pCompetences->tabCompetence[4] + pCharacters->pAttributs->Bonustab[5] );fflush(files);
	fprintf(files, "Réparation\t\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[5], pCharacters->pAttributs->Bonustab[3],\
pCharacters->pCompetences->tabCompetence[5] + pCharacters->pAttributs->Bonustab[3] );fflush(files);
	fprintf(files, "Sécurité\t\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[6], pCharacters->pAttributs->Bonustab[4],\
pCharacters->pCompetences->tabCompetence[6] + pCharacters->pAttributs->Bonustab[4]);fflush(files);
	fprintf(files, "PremierSecours\t:\t\t%d\t\t\t+\t\t\t%d\t\t\t\t=\t\t\t%d\n", pCharacters->pCompetences->tabCompetence[7], pCharacters->pAttributs->Bonustab[4],\
pCharacters->pCompetences->tabCompetence[7] + pCharacters->pAttributs->Bonustab[4]);fflush(files);
}

void displayDonFiles(FILE *files, Characters *pCharacters){
	fprintf(files, "\tDon en cours de Développement\n\n\tNombre de Don Potentiel :\t%d\n\n", pCharacters->pDon->donPresence);fflush(files);
	
	if(pCharacters->pDon->donPresence > 0){
		fprintf(files, "\t%s\n\n", pCharacters->pDon->plstPerks->namePerks);fflush(files);
		fprintf(files, "Tab de modif d'Attributs : \n\n");fflush(files);
		for (int i = 0; i < 7; ++i)
			fprintf(files, "\t\t ATT : %d\t\t Comp : %d\n", pCharacters->pDon->plstPerks->tabAttPerks[i], pCharacters->pDon->plstPerks->tabCompPerks[i]);
		fprintf(files, "\n");
		if(pCharacters->pDon->donPresence == 2){
			fprintf(files, "\t%s\n\n", pCharacters->pDon->plstPerks->next->namePerks);fflush(files);
			fprintf(files, "Tab de modif d'Attributs : \n\n");fflush(files);
			for (int i = 0; i < 7; ++i)
				fprintf(files, "\t\t ATT : %d\t\t Comp : %d\n", pCharacters->pDon->plstPerks->next->tabAttPerks[i], pCharacters->pDon->plstPerks->next->tabCompPerks[i]);
			fprintf(files, "\n");
		}
	}
}