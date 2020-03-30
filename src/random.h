#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "define.h"

int my_rand (void);
int Random (int _iMin, int _iMax);
int boolRandom(void);

int ccomp(char c, char *s);
char RandomStr(char *s);

char *RandomName(char *name);
char  *ft_strjoin(char const *s1, char const *s2);

#endif