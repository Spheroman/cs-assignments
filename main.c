#include <stdio.h>
#include <math.h>


int main() {
    int c, s, i, j, fail = 0, avg = 0, tot, temp, stud = 0;
    scanf("%i %i", &c, &s);
    int courses[c][3];
    for(i = 0; i < c; i++){
        for(j = 0; j < 3; j++){
            scanf("%i", &courses[i][j]);
        }
    }
    int scores[s][2];
    for(i = 0; i < s; i++){
        for(j = 0; j < 2; j++){
            scanf("%i", &scores[i][j]);
        }
    }
    int students[c];
    for(i = 0; i < c; i++){
        temp = 0;
        for(j = 0; j < c; j++)
            if(students[j] == courses[i][0])
                temp = 1;
        if(!temp){
            students[i] = courses[i][0];
            stud++;
        }
    }

    for(i = 0; i < stud; i++){
        tot = 0;
        avg = 0;
        for(j = 0; scores[j][0] != students[i]; j++);
        while(j < s){
            while(scores[j][0] == students[i]){
                avg+=scores[j][1];
                tot+=60;
                j++;
            }
            j++;
        }
        if(avg < tot)
            fail++;
    }
    printf("%i %i", stud, fail);

}
