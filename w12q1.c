#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int translate(int width, int height, int x, int y){
    return width * y + x;
}

int neighbors(int x, int y, char *board, int width, int height){
    int ctr = 0;
    if(x > 0 && y > 0 && board[translate(width, height, x-1, y-1)] == 1)
        ctr++;
    if(x > 0 && board[translate(width, height, x-1, y)] == 1)
        ctr++;
    if(x > 0 && y < height-1 && board[translate(width, height, x-1, y+1)] == 1)
        ctr++;
    if(y > 0 && board[translate(width, height, x, y-1)] == 1)
        ctr++;
    if(y < height-1 && board[translate(width, height, x, y+1)] == 1)
        ctr++;
    if(x < width-1 && y > 0 && board[translate(width, height, x+1, y-1)] == 1)
        ctr++;
    if(x < width-1 && board[translate(width, height, x+1, y)] == 1)
        ctr++;
    if(x < width-1 && y < height-1 && board[translate(width, height, x+1, y+1)] == 1)
        ctr++;
    return ctr;
}


char* checkstate(char *board, int width, int height){
    char *ret = (char *) malloc(height*width*sizeof(char));
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            int num = neighbors(x, y, board, width, height);
            if(board[translate(width, height, x, y)] && num < 2)
                ret[translate(width, height, x, y)] = 0;
            else if(board[translate(width, height, x, y)] && num > 3)
                ret[translate(width, height, x, y)] = 0;
            else if(board[translate(width, height, x, y)] && num == 2 || num == 3)
                ret[translate(width, height, x, y)] = 1;
            else if(!board[translate(width, height, x, y)] && num == 3)
                ret[translate(width, height, x, y)] = 1;
            else
                ret[translate(width, height, x, y)] = 0;
        }
    }

    return ret;
}


int main() {
    int rounds, i, length = 0, width = 0, height=-1;
    char *board, *new, e, temp = 'h';
    scanf("%i", &rounds, &e);
    while(temp != EOF){
        while((temp = getchar()) == '0' || temp == '1'){
            new = board;
            board = (char *) malloc((length+1)*sizeof(char));
            for(int j = 0; j < length; j++){
                board[j] = new[j];
            }
            board[length] = temp - '0';
            length++;
        }
        if(height == 0)
            width = length;
        height++;
    }
    for(i = 0; i < rounds; i++){
        board = checkstate(board, width, height);
    }
    for(i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%i", board[translate(width, height, j, i)]);
        }
        printf("\n");
    }
}
