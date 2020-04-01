#include "random.h"

int my_rand (void){
   static int tab[TABSIZERANDOM];
   static int first = 0;
   int index;
   int rn;

   if (first == 0){
      int i;

      srand (time (NULL));
      for (i = 0; i < TABSIZERANDOM; i++)
         tab[i] = rand();
      first = 1;
   }
   index = (int)(rand() / RAND_MAX * (TABSIZERANDOM - 1));
   rn = tab[index];
   tab[index] = rand();
   return (rn);
}

int Random (int _iMin, int _iMax){
	return (_iMin + (my_rand () % (_iMax-_iMin+1)));
}

int boolRandom(void){
	return(Random(0,1));
}

char *RandomName(char *name){

   char **tabname;
   tabname = (char **)malloc((20)*sizeof(char*));
   for (int i = 0; i < 20; ++i)
      *tabname = (char*)malloc((20)*sizeof(char));
   
   tabname[0] = "Aulra";
   tabname[1] = "Aaymr";
   tabname[2] = "Plo";
   tabname[3] = "Fihrin";
   tabname[4] = "Cin";
   tabname[5] = "Borsk";
   tabname[6] = "Kir";
   tabname[7] = "Taju";
   tabname[8] = "Bretir";
   tabname[9] = "Wald";
   
   tabname[10] = "Talpals";
   tabname[11] = "Tekka";
   tabname[12] = "Rancilis";
   tabname[13] = "Piett";
   tabname[14] = "Pananoida";
   tabname[15] = "Marelios";
   tabname[16] = "Nunn";
   tabname[17] = "Owen";
   tabname[18] = "Kalko";
   tabname[19] = "Zhytt";

   int i = Random(0,19);
   name = tabname[i];
   if(boolRandom()){
      name = ft_strjoin(name," ");
      i = Random(0, 19);
      name = ft_strjoin(name, tabname[i]);
   }
   free(tabname);
   return(name);
}
