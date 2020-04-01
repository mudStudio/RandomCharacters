#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "struct.h"
#include "random.h"
#include "manip.h"

#include <stdio.h>
#include <string.h>

//display in Term
void displayCharacters(Characters *pCharacters);

void displayAttributs(Characters *pCharacters);
void displayCompetences(Characters *pCharacters);
void displayDon(Characters *pCharacters);

// Put on files
void displayCharactersFiles(Characters *pCharacters);

void displayAttributsFiles(FILE *files, Characters *pCharacters);
void displayCompetencesFiles(FILE *files, Characters *pCharacters);
void displayDonFiles(FILE *files, Characters *pCharacters);

#endif