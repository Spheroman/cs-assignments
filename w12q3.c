#include <stdio.h>
#include <stdlib.h>
int maijn(){
    char in = '+', operator = '+';
    int tot = 0, num;
    while(1){
        num = 0;
        scanf("%d", &num);
        //printf("%d\n", num);
        //while((in = getchar()) >= '0' && in <= '9'){
        //    num = (num * 10) + (in - '0');
        //}
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
        //if(in == EOF)
        //    break;
        if(scanf(" %c ", &operator) == EOF)
            break;
        //if(in == EOF)
        //    break;
        //if(getchar() == EOF)
        //    break;
        //operator = in;
    }
    printf("%i", tot);
}