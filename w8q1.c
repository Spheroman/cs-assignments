#include <stdio.h>
#include <math.h>

int main() {
    char in[10000];
    char temp;
    int ctr = 0;
    while(scanf("%c", &temp) != EOF){
        in[ctr] = temp;
        ctr++;
    }
    int end=1;
    for(int i = 0; in[i] != 0; i++){
        if(in[i] == '.')
            end = 1;
        if((in[i] >= 'A' && in[i] <= 'Z' || in[i] == '%') && end){
            end = 0;
        }
        if(in[i] >= 'a' && in[i] <= 'z' && end){
            end = 0;
            in[i] += 'A' - 'a';
        }
    }
    for(int i = 0; in[i] > 0 && in [i] < 128; i++){
        printf("%c", in[i]);
    }

}