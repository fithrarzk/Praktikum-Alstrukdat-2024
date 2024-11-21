#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakter.h"

int isValidIPv4Lay(Word w) {
    int segmentCount = 0;
    int numValue = 0;
    int i = 0;
    int startSegment = 1;

    while (i < w.Length) {
        if (w.TabWord[i] == '@') {
            if (startSegment || w.TabWord[i - 1] == '@' || (numValue == 0 && (i > 1 && w.TabWord[i - 2] == '0'))) {
                return 0;
            }
            segmentCount++;
            numValue = 0;
            startSegment = 1;
        } else if (w.TabWord[i] >= '0' && w.TabWord[i] <= '9') {
            if (startSegment && w.TabWord[i] == '0' && (i + 1 < w.Length && w.TabWord[i + 1] != '@')) {
                return 0;
            }
            startSegment = 0;
            numValue = numValue * 10 + (w.TabWord[i] - '0');
            if (numValue > 255) {
                return 0; 
            }
        } else {
            return 0; 
        }
        i++;
    }

    if (w.TabWord[w.Length - 1] == '@') {
        return 0;
    }
    return (segmentCount == 3);
}

int main() {
    int i = 0; 
    STARTWORD();

    while (!EndWord) {
        if (i == 0) {
            if (isValidIPv4Lay(currentWord)) {
                printf("4Lay");
            } else {
                printf("ewh");
            }
        } else {
            if (isValidIPv4Lay(currentWord)) {
                printf(" 4Lay");
            } else {
                printf(" ewh");
            }
        }
        i++;
        ADVWORD();
    }
    printf("\n");
    return 0;
}
