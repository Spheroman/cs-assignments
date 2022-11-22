#include <stdio.h>
#include <math.h>

int main() {
    char in[10000];
    char ascii[128];
    for(int i = 0; i < 128; i++) {
        ascii[i] = -2;
    }
    scanf("%s", &in);
    int cur = 0, max = 0, a = -1, b = 0, ma = 0;
    while (in[cur] != 0) {
        if(ascii[in[cur]] > a){
            a = ascii[in[cur]];
        }
        if(max < (cur - a)){
            max = cur - a;
            ma = a;
            b = cur;
        }
        ascii[in[cur]] = cur;
        cur++;
    }
    for(int i = ma+1; i <= b; i++){
        printf("%c", in[i]);
    }

}
