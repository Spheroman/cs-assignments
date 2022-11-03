#include <stdio.h>

int main() {
    int len, prime, i, plen = 0, x;
    scanf("%i", &len);
    int arr[len], primes[len];
    for(i = 0; i < len; i++){
        scanf("%i", &arr[i]);
    }
    for(i = 0; i < len; i++){
        prime = 0;
        for(x = 2; x <= arr[i]/2+1; x++){
            prime = 1;
            if(arr[i]%x == 0 && x != arr[i]){
                prime = 0;
                break;
            }
        }
        if(prime){
            primes[plen] = arr[i];
            plen++;
            for(x = i+1; x < len; x++)
                arr[x-1] = arr[x];
            len--;
            i--;
        }

    }
    i = -1;
    while(i < plen-2){
        i++;
        if(primes[i] < primes[i+1]){
            x = primes[i];
            primes[i] = primes[i+1];
            primes[i+1] = x;
            i = -1;
        }
    }
    i = -1;
    while(i < len-2){
        i++;
        if(arr[i] > arr[i+1]){
            x = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = x;
            i = -1;
        }
    }
    for(i = 0; i < plen; i++){
        printf("%i ", primes[i]);
    }
    for(i = 0; i < len; i++){
        printf("%i ", arr[i]);
    }
}
