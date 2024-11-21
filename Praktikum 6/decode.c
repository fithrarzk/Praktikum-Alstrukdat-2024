#include <stdio.h>
#include "stack.h"

char result[10001];
int residx = 0;

void add(char c) {
    if (residx < 10000) {
        result[residx++] = c;
        result[residx] = '\0';
    }
}

int main() {
    int N;
    Stack nums, chars;
    CreateEmpty(&nums);
    CreateEmpty(&chars);
    scanf("%d\n", &N);
    
    char ch;
    int num = 0;
    int reps[100]; 
    int reptop = -1; 
    
    for (int i = 0; i < N; i++) {
        scanf("%c", &ch);
        
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0'); 
        } else if (ch == '[') {
            reps[++reptop] = num;
            num = 0;
            Push(&chars, ch);
        } else if (ch == ']') {
            char temp[10001];
            int tidx = 0;
            char top;
            
            while (!IsEmpty(chars)) {
                Pop(&chars, &top);
                if (top == '[') break;
                temp[tidx++] = top;
            }
        
            char seg[10001];
            for (int j = 0; j < tidx; j++) {
                seg[j] = temp[tidx - 1 - j];
            }
            seg[tidx] = '\0';
            
            int times = reps[reptop--];
          
            for (int j = 0; j < times; j++) {
                for (int k = 0; k < tidx; k++) {
                    Push(&chars, seg[k]);
                }
            }
        } else {
            Push(&chars, ch); 
        }
    }
  
    while (!IsEmpty(chars)) {
        char c;
        Pop(&chars, &c);
        add(c);
    }
  
    for (int i = residx - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
    
    return 0;
}