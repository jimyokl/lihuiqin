#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

//  ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#define BUF 256
int has_ch(char ch, const char * line);   

int
main(int argc, char *argv[])
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((nread = getline(&line, &len, stream)) != -1) {
        printf("Retrieved line of length %zd:\n", nread);
        fwrite(line, nread, 1, stdout);
    }

    free(line);
    fclose(stream);

    // c primer plus chapter 13 "review questons--quiz 5":
    // program that takes 1 command-line arguments, argument is a filename
    //given a character, 
    //The program print only those lines in the file containing the given character.
    printf("\nprint only those lines in the file containing the given character 'o':\n");
    FILE * fp;
    char ch;
    char line_str[BUF];
   
    ch = 'o';
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line_str,BUF,fp) != NULL)
    {
        if (has_ch(ch,line_str))
            fputs(line_str,stdout);
    }
    fclose(fp);
   
    exit(EXIT_SUCCESS);
}

int has_ch(char ch, const char * line)
{
    while (*line)
    if (ch == *line++)
      return(1);
    
    return 0;
}  