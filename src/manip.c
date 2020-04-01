#include "manip.h"


char  *ft_strjoin(char const *s1, char const *s2)
{
   char  *str;
   int      len;

   len = strlen(s1) + strlen(s2);
   str = (char *)malloc(sizeof(*str) * (len + 1));
   if (str == NULL)
      return (NULL);
   strcpy(str, s1);
   strcat(str, s2);
   return (str);
}

void printfflush(char *s){
	printf("%s", s);fflush(stdout);
}