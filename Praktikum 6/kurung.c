#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main()
{
    int N, i;
    char ch;
    boolean valid = true;
    int count1 = 0, count2 = 0, count3 = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++){
        scanf(" %c", &ch);
        if (ch =='['){
            count1 += 1;
        }
        if (ch =='('){
            count2 += 1;
        }
        if (ch =='{'){
            count3 += 1;
        }
        if (ch ==']'){
            count1 -= 1;
            if (count1 < 0){
                valid = false;
            }
        }
        if (ch ==')'){
            count2 -= 1;
            if (count2 < 0){
                valid = false;
            }
        }
        if (ch =='}'){
            count3 -= 1;
            if (count3 < 0){
                valid = false;
            }
        }
    }
    if (count1 == 0 && count2 == 0 && count3 == 0 && valid){
        printf("Valid\n");
    }
    else {
        printf ("Invalid\n");
    }
    return 0;
}