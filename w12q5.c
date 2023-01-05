#include <stdio.h>
#include <stdlib.h>

int f(int x){
    return 3*x+1;
}

int g(int x, int y){
    return x*y-3;
}

int func(char *in, int idx){
    char cur = in[idx];
    if(cur == 'F'){
        //printf("f > ");
        idx+=2;
        int x = func(in, idx);
        //printf("f(%i)=%i\n", x, f(x));
        return f(x);
    }
    if(cur == 'G'){
        //printf("g > ");
        idx+=2;
        int temp = idx;
        int level = 0;
        while(1){
            if(in[temp] == '(')
                level++;
            if(in[temp] == ')')
                level--;
            if(in[temp] == ',' && level == 0)
                break;
            temp++;
        }
        int x = func(in, idx);
        int y = func(in, temp+2);
        //printf("g(%i %i)\n", x, y);
        return g(x, y);
    }
    int num = 0;
    //printf("num > %i\n", in[idx]);
    while(in[idx] >= '0' && in[idx] <= '9'){
        num = num * 10 + in[idx]-'0';
        idx++;
    }
    //printf("%i\n", num);
    return num;

}

int main() {
    char in[1000];
    int i = 0;
    while((in[i] = getchar()) != EOF){
        i++;
    }
    //printf("%s", in);
    int out = func(in, 0);
    printf("%i", out);

}