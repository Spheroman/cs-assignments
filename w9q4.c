#include <stdio.h>
#include <math.h>


int main() {
    int c, s, i, j, k, fail = 0, temp, stud = 0;
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
    int students[3];//0=total score, 1=passing score, 2=failed classes
    for(i = 0; i < c; i++){
        if(courses[i][1] != 0){//if we haven't already found the student
            students[2]=0;
            temp = courses[i][1];
            for(j = i; j < c; j++) {//find same student id
                if (courses[j][1] == temp) {//if its same
                    //printf("%i\n", temp);
                    students[0]=0;
                    students[1]=0;
                    for (k = 0; k < s; k++) {//calculate score for sid
                        if (courses[j][0] == scores[k][0]) {
                            students[0] += scores[k][1];
                            students[1] += 60;
                        }
                    }
                    if(students[0] < students[1]){ //check if failed
                        students[2]=1;
                        //printf("fail %i, %i, %i\n", temp, students[i][0], students[i][1]);
                    }
                    courses[j][1]=0;//set student id = 0, so it doesn't get looped into again
                }
            }
            //printf("check %i %i\n", temp, students[i][2]);
            if(students[2]==1)
                fail++;
            stud++;
        }
    }
    printf("%i %i", stud, fail);

}
