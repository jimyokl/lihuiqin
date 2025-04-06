#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int score = 0, ret_scanf = 0;
    printf("Enter your score number:");
    ret_scanf = scanf("%d", &score);
    if (ret_scanf != 1) {
        fprintf(stderr, "Invalid input. Please enter a number.\n");
        exit(1);
    }
    if (score < 0.0 || score > 100.0) {
        fprintf(stderr, "EINVAL, invalid score number, please enter a number between 0 and 100.\n");
        exit(1);
    }
    int score_divid_10 = score / 10;
    printf("Score input is: %d.\n", score);
    printf("Score divided by 10 is: %d, it's used for switch.\n", score_divid_10);
    switch (score_divid_10)
    {
    case 10:
    case 9:
        printf("Your grade classification is: A.\n");
        break;
    case 8:
        printf("Your grade classification is: B.\n");
        break;
    case 7:
        printf("Your grade classification is: C.\n");
        break;
    case 6:
        printf("Your grade classification is: D.\n");
        break;
    
    // warning: this is not a good practice
    // 这里的default最好放出错的情况,
    // 把case 5/4/3/2/1/0都放在default之前，输出E/F
    // 这样就能避免分数输入错误的情况
    default:
        printf("Your grade classification is: E/F, fail.\n");      // warning: this is not a good practice
        break;
    }
/*    switch(score)
    {
        case 100:
        case 99:
        case 98:
        case 97:
        case 96:
        case 95:
        case 94:
        case 93:
        case 92:
        case 91:
        case 90:
            printf("Your grade classification is: A.\n");
            break;
        case 89:
        case 88:
        case 87:
        case 86:
        case 85:
        case 84:
        case 83:
        case 82:
        case 81:
        case 80:
            printf("Your grade classification is: B.\n");
            break;
        default:
            printf("Your grade classification is: E/F, fail.\n");
            break;
    }   */
    exit(0);
}