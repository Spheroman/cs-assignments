#include <stdio.h>
#include <math.h>


int main() {
    int r, x = 0, y = 0, dir = 1, px=0, py=0, c = 0;
    scanf("%i", &r);
    int arr[r][r];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            scanf("%i", &arr[i][j]);
        }
    }
    if(arr[0][0]){
        printf("No");
        return 0;
    }
    while((x!=r-1) || (y!=r-1)){
        for(int v = dir-1; v < dir+4; v++){
            if(v%4 == 0)
                x++;
            else if(v%4 == 1)
                y++;
            else if(v%4 == 2)
                x--;
            else if(v%4 == 3)
                y--;
            if(arr[y][x] || x < 0 || y < 0 || x == r || y == r) {
                x = px;
                y = py;
            }
            else if(v >=0){
                dir = v;
                break;
            }
        }
        px = x;
        py = y;
        if(c > r*r){
            printf("No");
            return 0;
        }
        c++;
    }
    printf("Yes");
}
