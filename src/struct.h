#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct Attributs{
	
	int tabAttributs[7];

	int Bonustab[7];

	char *Sex;
	int Sexuality; // define preference : undifined, Homo, Hetero, Bi, Pan, A (0 to 5) 
}Attributs;

typedef struct Competences{

	int tabCompetence[8];
}Competences;

typedef struct lstPerks{
	char *namePerks;
	int tabAttPerks[7];
	int tabCompPerks[8];
	struct lstPerks *next;
}lstPerks;

typedef struct Don{
	int donPresence;
	lstPerks *plstPerks;
}Don;

typedef struct Characters{
	char *nameCharacters;

	Attributs 	*pAttributs;
	Competences *pCompetences;
	Don 		*pDon;

	int nbAttack;
	int VAttack;
	int VDefence;

	int Vigueur;
	int Reflexe;
	int Volonte;

	int VitaliteMax;
	int VitaliteAct;

	int ForceMax;
	int ForceAct;
}Characters;

#endif