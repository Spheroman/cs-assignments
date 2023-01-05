#include <stdio.h>
#include <stdlib.h>
int maijn(){
    char in = '+', operator = '+';
    int tot = 0, num;
    while(1){
        num = 0;
        scanf("%d", &num);
        if(operator == '+'){
            tot += num;
        }
        else if(operator == '-'){
            tot -= num;
        }
        else if(operator == '*'){
            tot *= num;
        }
        else if(operator == '/'){
            tot /= num;
        }
        if(scanf(" %c ", &operator) == EOF)
            break;
    }
    printf("%i", tot);
}