#include <stdio.h>
#include <math.h>

int main() {
    int len, i, m = 0, r = 0;
    scanf("%i", &len);
    int arr[len];
    for(i = 0; i < len; i++){
        scanf("%i", &arr[i]);
    }
    for(i = 0; i < len-1; i++) {
        if (arr[i] <= arr[i + 1]) {
            r++;
        } else r = 0;
        if (r > m)
            m = r;
    }
    printf("%i", m);
}