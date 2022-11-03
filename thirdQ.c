#include <stdio.h>
#include <math.h>

int main() {
    int len,  i;
    double u=0, ret = 0, l;
    scanf("%i", &len);
    double arr[len];
    for(i = 0; i < len; i++){
        scanf("%lf", &arr[i]);
        u += arr[i];
    }
    u/=len;
    for(i = 0; i < len; i++){
        ret += (arr[i] - u) * (arr[i] - u);
    }
    printf("%0.2lf", sqrt(ret/len));
}
