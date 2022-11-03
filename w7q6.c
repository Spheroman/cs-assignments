#include <stdio.h>
#include <math.h>

int main() {
    int in, out[32], cur = -1;
    scanf("%i", &in);
    while(in > 0){
        cur++;
        out[cur] = in%2;
        in/=2;
    }
    for(int i = cur; i >= 0; i--){
        printf("%i", out[i]);
    }
}
