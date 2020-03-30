#include "init.h"

void Init(Characters *pCharacters){
	pCharacters->nameCharacters = RandomName(pCharacters->nameCharacters);
	
	if(pCharacters->pAttributs == NULL){
		pCharacters->pAttributs = calloc(1,sizeof(Attributs));
		if(pCharacters->pAttributs == NULL){
	        fprintf(stderr, "ERROR : pAttributs creation failed.\n");
	        exit(EXIT_FAILURE);
		}
	}
	
	InitAttributs(pCharacters->pAttributs);

	if(pCharacters->pCompetences == NULL){
		pCharacters->pCompetences = calloc(1,sizeof(Competences));
		if(pCharacters->pCompetences == NULL){
	        fprintf(stderr, "ERROR : Competences creation failed.\n");
	        exit(EXIT_FAILURE);
		}
	}

	InitCompetences(pCharacters->pCompetences);
	if(pCharacters->pDon == NULL){
		pCharacters->pDon = calloc(1,sizeof(Don));
		if(pCharacters->pDon == NULL){
	        fprintf(stderr, "ERROR : Don creation failed.\n");
	        exit(EXIT_FAILURE);
		}
	}
	InitDon(pCharacters->pDon);

	pCharacters->nbAttack = 1;
	pCharacters->VAttack = 1;
	pCharacters->VDefence = 0;

	pCharacters->Vigueur = 0;
	pCharacters->Reflexe = 0;
	pCharacters->Volonte = 0;

	pCharacters->VitaliteMax = 100;
	pCharacters->VitaliteAct = 100;
	
//	pCharacters->ForceMax = 100;
//	pCharacters->ForceAct = 100;
}

void InitAttributs(Attributs *pAttributs){

//define Sex
	int bio =  Random(-1,1);
	if(bio == -1)
		pAttributs->Sex = "Male";
	else if(bio == 1)
		pAttributs->Sex = "Female";
	else
		pAttributs->Sex = "Unidentified";

// define preference : Homo, Hetero, Bi, Pan, A
	int pref = Random(0,4);
	char tab[5][14] = {"Homosexual", "Heterosexual", "Bisexual", "Pansexual", "Asexual"};
	pAttributs->Sexuality = tab[pref];

//define Attributs 
	pAttributs->tabAttributs[0] = 8;
	pAttributs->tabAttributs[1] = 8;
	pAttributs->tabAttributs[2] = 8;
	pAttributs->tabAttributs[3] = 8;
	pAttributs->tabAttributs[4] = 8;
	pAttributs->tabAttributs[5] = 8;
	pAttributs->tabAttributs[6] = 10;

	pAttributs->Bonustab[0] = (pAttributs->tabAttributs[0] - NORMALSTATS)/2; 	//BForce
	pAttributs->Bonustab[1] = (pAttributs->tabAttributs[1] - NORMALSTATS)/2;	//BDexterite
	pAttributs->Bonustab[2] = (pAttributs->tabAttributs[2] - NORMALSTATS)/2;	//BConstitution
	pAttributs->Bonustab[3] = (pAttributs->tabAttributs[3] - NORMALSTATS)/2;	//BInteligence
	pAttributs->Bonustab[4] = (pAttributs->tabAttributs[4] - NORMALSTATS)/2;	//BSagesse
	pAttributs->Bonustab[5] = (pAttributs->tabAttributs[5] - NORMALSTATS)/2;	//BCharisme
	pAttributs->Bonustab[6] = (pAttributs->tabAttributs[6] - NORMALSTATS)/2;	//BChance
//add some experience
	updateAttributs(pAttributs);
}

void updateAttributs(Attributs *pAttributs){
	int attributPoint = ATTRIBUTPOINT;
	while(attributPoint > 0){
		int i = Random(0,5);
		if(pAttributs->tabAttributs[i] >= 10 && pAttributs->tabAttributs[i] < LIMITATTRIBUTSCREATION){
			pAttributs->tabAttributs[i] += 1;
			if(pAttributs->Bonustab[i] < 1)
				attributPoint -= 1;
			else
				attributPoint -= pAttributs->Bonustab[i];
			pAttributs->Bonustab[i] = (pAttributs->tabAttributs[i] - NORMALSTATS)/2;
		}
		if(pAttributs->tabAttributs[i] <= 9){
			pAttributs->tabAttributs[i] += 1;
			pAttributs->Bonustab[i] -= -1;
			attributPoint--;
		}
	}
	for (int i = 0; i < 5; i++){
		if(pAttributs->tabAttributs[i] >= 10)
			pAttributs->Bonustab[i] = (pAttributs->tabAttributs[i] - NORMALSTATS)/2;
		if(pAttributs->tabAttributs[i] == 9)
			pAttributs->Bonustab[i] = (pAttributs->tabAttributs[i] - NORMALSTATS)/2 -1;
	}
}

void InitCompetences(Competences *pCompetences){
	pCompetences->tabCompetence[0] = 0; 	//Informatique
	pCompetences->tabCompetence[1] = 0;		//Demolition
	pCompetences->tabCompetence[2] = 0;		//Discretion
	pCompetences->tabCompetence[3] = 0;		//Vigilance
	pCompetences->tabCompetence[4] = 0;		//Persuasion
	pCompetences->tabCompetence[5] = 0;		//Reparation
	pCompetences->tabCompetence[6] = 0;		//Securite
	pCompetences->tabCompetence[7] = 0;		//PremierSecours

	updateCompetences(pCompetences);
}

void updateCompetences(Competences *pCompetences){
	int competencesPoint = COMPETENCESPOINT;
	int tab[NBCOMPETENCEINIT];
	for (int i = 0; i < NBCOMPETENCEINIT; i++)
		tab[i] = Random(0,7);
	while(competencesPoint > 0){
		int test = Random(0,7);
		for (int i = 0; i < NBCOMPETENCEINIT; ++i){
			if(test == tab[i] && pCompetences->tabCompetence[test] < LIMITCLASS){
				int addstats = Random(3,4);
				pCompetences->tabCompetence[test] = addstats;
				competencesPoint-= addstats;
			}
		}
		if(pCompetences->tabCompetence[test] < LIMITHORSCLASS){
			pCompetences->tabCompetence[test] += 1;
			competencesPoint-= 2;
		}
	}
}

void CreatPerks(lstPerks *firstPerks){ // App modif 

	firstPerks->namePerks = "NomPerks :\t";
	for (int i = 0; i < 7; ++i)
		firstPerks->tabAttPerks[i] = 0;
	for (int i = 0; i < 8; ++i)
		firstPerks->tabCompPerks[i] = 0;
	firstPerks->next = &(*firstPerks);
}

void InitDon(Don *pDon){
	int test = Random(0,100);
	if(pDon->plstPerks == NULL) {
		pDon->plstPerks = calloc(1, sizeof(lstPerks));
		if(pDon->plstPerks == NULL){
	        fprintf(stderr, "ERROR : pDon->plstPerks creation failed.\n");
			exit(EXIT_FAILURE);
		}
	}
	if(test <= 55){
		pDon->donPresence = 2;
		CreatPerks(pDon->plstPerks);
		if(pDon->plstPerks->next == NULL){
			pDon->plstPerks->next = calloc(1, sizeof(lstPerks));
				if(pDon->plstPerks->next == NULL){
		    	    fprintf(stderr, "ERROR : pDon->plstPerks->next creation failed.\n");
					exit(EXIT_FAILURE);
				}
		}
		CreatPerks(pDon->plstPerks->next);
	}
	else if(test > 65 && test < 150){
		pDon->donPresence = 1;
		CreatPerks(pDon->plstPerks);
	}
	else
		pDon->donPresence = 0;
}


void freeStruct(Characters *pCharacters){
	
//Free Attributs
	if(pCharacters->pAttributs != NULL)
		free(pCharacters->pAttributs);
//Free Competences
	if(pCharacters->pCompetences != NULL)
		free(pCharacters->pCompetences);
//Free Don
	if(pCharacters->pDon->plstPerks->next != NULL)
		free(pCharacters->pDon->plstPerks->next);
	if(pCharacters->pDon->plstPerks != NULL)
		free(pCharacters->pDon->plstPerks);
	if(pCharacters->pDon != NULL)
		free(pCharacters->pDon);
//Free Characters
 	if(pCharacters != NULL)
		free(pCharacters);
}