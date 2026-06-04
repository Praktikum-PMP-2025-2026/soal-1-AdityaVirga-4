#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    // Baca input 
    if (scanf("%1004[^\n]", s) != 1) return 0; 
    
    int n = strlen(s);
    int remove[1005] = {0}; 

    // Mencari ')'
    int kurung_tutup = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            kurung_tutup++;
        } else if(s[i] == ')') {
            if(kurung_tutup == 0) {
                remove[i] = 1; 
            } else {
                kurung_tutup--;
            }
        }
    }

    // Mencari '('
    int kurung_buka = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')') {
            kurung_buka++;
        } else if(s[i] == '(') {
            if(kurung_buka == 0) {
                remove[i] = 1; 
            } else {
                kurung_buka--;
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
