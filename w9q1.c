#include <stdio.h>
#include <math.h>

int main() {
    int r, c, in, a, b, d;
    scanf("%i %i %i", &r, &c, &in);
    int arr[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < in; i++){
        scanf("%i %i %i", &a, &b, &d);
        arr[a][b] = d;
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}