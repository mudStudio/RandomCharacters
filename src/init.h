#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "struct.h"
#include "random.h"

void Init(Characters *pCharacters);

void InitAttributs(Attributs *pAttributs);
void updateAttributs(Attributs *pAttributs);

void InitCompetences(Competences *pCompetences);
void updateCompetences(Competences *pCompetences);

void CreatPerks(lstPerks *firstPerks);
void InitDon(Don *pDon);

void freeStruct(Characters *pCharacters);

#endif