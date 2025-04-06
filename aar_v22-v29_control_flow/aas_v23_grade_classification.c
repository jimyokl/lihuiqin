//grades_classification
/*score: [90,100] A
         [80,90)  B
         [70,80)  C
         [60,70)  D
         [0,60)   E     */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int score, ret_scanf;
    printf("Please enter your score[0-100]: ");
    ret_scanf = scanf("%d", &score);                                // %d后面不要加 \n
    if(ret_scanf != 1) {                                          // scanf返回值
        fprintf(stderr, "Invalid input.\n");
        exit(1);    
    }
    if(score < 0 || score > 100) {                               // score范围
        fprintf(stderr, "Invalid score.\n");
        exit(1);    
    }
    if(score<=100 && score>=90) {
        printf("your grade classification is A\n");
    }else if(score<90 && score>=80) {
        printf("your grade classification is B\n");
    }else if(score<80 && score>=70) {
        printf("your grade classification is C\n");
    }else if(score<70 && score>=60) {
        printf("your grade classification is D\n");
    }else if(score<60 && score>=0) {
        printf("your grade classification is E/F (fail).\n");
    }

    exit(0);    
}