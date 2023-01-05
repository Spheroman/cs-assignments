#include <stdio.h>

int main() {
    char in[10000];
    int i = 0, j, h;
    while ((in[i] = getchar()) != '\n') {
        i++;
    }
    i--;
    while (i >= 0) {
        h = i;
        while (in[i] != ' ' && i > -1) {
            i--;
        }
        i++;
        j = i-1;
        while (i <= h) {
            printf("%c", in[i]);
            i++;
        }
        i = j-1;
        if(i >= 0)
            printf(" ");
    }
}