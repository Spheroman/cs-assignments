#include <stdio.h>
#include <math.h>


int main() {
    int r, c,  x = 0, y = 0, dir = 0, px=0, py=0, bx = -1, by = 0, j, i, tempx = 1, tempy = 1;
    scanf("%i %i", &r, &c);
    int arr[r][c];
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%i", &arr[i][j]);
        }
    }
    int tx = c, ty = r;
    for(int i = 0; i < r*c; i++){
        printf("%i ", arr[y][x]);
        if(dir%4 == 0)
            x++;
        else if(dir%4 == 1)
            y++;
        else if(dir%4 == 2)
            x--;
        else if(dir%4 == 3)
            y--;
        if(x < bx || y < by ||(x >= tx && tempx)||(y >= ty && tempy)) {
            if(dir%4 == 0)
                bx++;
            else if(dir%4 == 1)
                by++;
            else if(dir%4 == 2)
                tx--;
            else if(dir%4 == 3)
                ty--;
            dir++;
            x = px;
            y = py;
            if(dir%4 == 0)
                x++;
            else if(dir%4 == 1)
                y++;
            else if(dir%4 == 2)
                x--;
            else if(dir%4 == 3)
                y--;
        }
        px = x;
        py = y;
    }
}
