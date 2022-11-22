#include <stdio.h>
#include <math.h>

int main() {
    char values[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int in, i;
    scanf("%i", &in);
    for(i = 0; i < in/1000; i++)
        printf("M");
    in%=1000;
    if(in >= 900)
        printf("CM");
    else{ if(in >= 500)
            printf("D");
        in%=500;
        if(in >= 400)
            printf("CD");
        else for(i = 0; i < in/100; i++)
                printf("C");
    }
    in%=100;
    if(in >= 90)
        printf("XC");
    else {
        if (in >= 50)
            printf("L");
        in %= 50;
        if (in >= 40)
            printf("XL");
        else for (i = 0; i < in / 10; i++)
                printf("X");
    }
    in %= 10;
    if (in >= 9)
        printf("IX");
    else {
        if (in >= 5)
            printf("V");
        in %= 5;
        if (in == 4)
            printf("IV");
        else for (i = 0; i < in / 1; i++)
                printf("I");
    }


}
