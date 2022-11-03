#include <stdio.h>
#include <math.h>

int main() {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, cx1, cy1, cx2, cy2;
    scanf("%i %i %i %i %i %i %i %i", &ax1, &ay1, &ax2, &ay2, &bx1, &by1, &bx2, &by2);
    if(ay1 <= by2 || ay2 >= by1 || ax1 >= bx2 || ax2 <= bx1)
        printf("0");
    else{
        if(ay1 <= by1) cy1 = ay1;
        else cy1 = by1;
        if(ay2 >= by2) cy2 = ay2;
        else cy2 = by2;
        if(ax1 >= bx1) cx1 = ax1;
        else cx1 = bx1;
        if(ax2 <= bx2) cx2 = ax2;
        else cx2 = bx2;
        printf("%i", (cx2-cx1)*(cy1-cy2));
    }
}
