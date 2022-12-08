#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *replace(char *source, char *pattern, char *replacement)
{
    int len = 0, replacelen = 0, patternlen = 0, e;
    while(source[len] != 0)
        len++;
    while(pattern[patternlen] != 0)
        patternlen++;
    while(replacement[replacelen] != 0)
        replacelen++;
    int i, j;
    for (i = 0; source[i] != '\0'; i++){
        if (source[i] == pattern[0]){
            for (j = 0; pattern[j] != '\0'; j++){
                if (source[i + j] != pattern[j])
                    break;
            }
            if (pattern[j] == '\0')
                break;
        }
    }
    if (source[i] == '\0')
        return source;
    char *ret = malloc(len + replacelen - patternlen + 1);
    for(e = 0; e < i; e++){
        ret[e] = source[e];
    }
    for(e = i; e - i < replacelen; e++){
        ret[e] = replacement[e - i];
    }
    while(source[e - replacelen + patternlen] != '\0'){
        ret[e] = source[e - replacelen + patternlen];
        e++;
    }
    ret[e] = '\0';
    return ret;
}


char *replaceAll(char *source, char *pattern, char *replacement)
{
    int len = 0, replacelen = 0, patternlen = 0, e;
    while(source[len] != 0)
        len++;
    while(pattern[patternlen] != 0)
        patternlen++;
    while(replacement[replacelen] != 0)
        replacelen++;
    int i, j;
    for (i = 0; source[i] != '\0'; i++){
        if (source[i] == pattern[0]){
            for (j = 0; pattern[j] != '\0'; j++){
                if (source[i + j] != pattern[j])
                    break;
            }
            if (pattern[j] == '\0')
                break;
        }
    }
    if (source[i] == '\0')
        return source;
    char *ret = malloc(len + replacelen - patternlen + 1);
    
}

int main() {
    char source[100], pattern[100], replacement[100];
    scanf("%s", source);
    scanf("%s", pattern);
    scanf("%s", replacement);
    char *done = replaceAll(source, pattern, replacement);
    printf("%s", done);

}
