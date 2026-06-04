#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    // Baca input 
    if (scanf("%1004[^\n]", s) != 1) return 0; 
    
    int n = strlen(s);
    int remove[1005] = {0}; 

    // Mencari ')'
    int open_count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            open_count++;
        } else if(s[i] == ')') {
            if(open_count == 0) {
                remove[i] = 1; 
            } else {
                open_count--;
            }
        }
    }

    // Mencari '('
    int close_count = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')') {
            close_count++;
        } else if(s[i] == '(') {
            if(close_count == 0) {
                remove[i] = 1; 
            } else {
                close_count--;
            }
        }
    }

    // Hasil 
    for(int i = 0; i < n; i++) {
        if(!remove[i]) {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
