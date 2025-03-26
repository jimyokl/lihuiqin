#include <stdlib.h>
#include <stdio.h>
#define STLEN 14
int main(void)
{
     char words[STLEN]; // STLEN=14
     puts("Enter a string, then press enter, if your string is less than 14, then '\\n' will be stored.");
     fgets(words, STLEN, stdin);
     printf("Your string will be stored in a char array: words[14].\n");
     printf("output with puts(), if your string is less than 13, then '\\n' will be printed:\n");
     puts(words);
     printf("output with fputs(), if your string is less than 13, then '\\n' will be printed:\n");
     fputs(words, stdout);
     
     puts("Enter another string, please:");
     fgets(words, STLEN, stdin);
     printf("Your string twice (puts(), then fputs()):\n");
     puts(words);
     fputs(words, stdout);
     puts("Done.");

     char words_str[STLEN];
      puts("Enter strings (empty line to quit):");
      while (fgets(words_str, STLEN, stdin) != NULL && words_str[0] != '\n')
      // while (fgets(words_str, STLEN, stdin) != NULL)
          fputs(words_str, stdout);
      puts("Done.");

     exit(0);
 }  

  /*  fgets2.c  -- using fgets() and fputs() */
//   #include <stdio.h>
//   #define STLEN 10
//   int main(void)
//       return 0;
//   }  