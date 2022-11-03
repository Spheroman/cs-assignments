#include <stdio.h>
#include <math.h>

int main()
{
    double a1, b1, c1, a2, b2, c2, x, y;
    scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2);
    if(a1/b1 == a2/b2 || (a1==0 && b1==0) || (a2==0 && b2 == 0)){
        printf("NO");
    }
    else{
        x = (b2*c1-b1*c2)/(a1*b2-a2*b1);
        y = (-a1*x+c1)/b1;
        printf("(%.2lf, %.2lf)", x, y);
    }

}