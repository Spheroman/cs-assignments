#include <stdio.h>
#include <stdlib.h>
/*******************************************
function name: replace
description: When mode is 1, replace the first target finded in source with the replacement.
             When mode is 2, replace all the target in source with replacement until there are no target can find in source.
return value: Return the result after replace.
*******************************************/
char *replace(char *source, char *target, char *replacement, int mode)
{
    int len = 0, replacelen = 0, patternlen = 0, e;
    while(source[len] != 0)
        len++;
    while(target[patternlen] != 0)
        patternlen++;
    while(replacement[replacelen] != 0)
        replacelen++;
    int i, j;
    for (i = 0; source[i] != '\0'; i++){
        if (source[i] == target[0]){
            for (j = 0; target[j] != '\0'; j++){
                if (source[i + j] != target[j])
                    break;
            }
            if (target[j] == '\0')
                break;
        }
    }
    if (source[i] == '\0')
        return source;
    char *ret = malloc(len + replacelen - patternlen + 1);
    char *ret2 = malloc(len + replacelen - patternlen + 1);
    for(e = 0; e < i; e++){
        ret[e] = source[e];
    }
    for(e = i; e - i < replacelen; e++){
        ret[e] = replacement[e - i];
    }
    if(mode == 1){
        while(source[e - replacelen + patternlen] != '\0'){
            ret[e] = source[e - replacelen + patternlen];
            e++;
        }
        ret[e] = '\0';
        return ret;
    }
    int temp = e;
    j = e;
    while(source[j - replacelen + patternlen] != '\0'){
        ret2[j-temp] = source[j - replacelen + patternlen];
        j++;
    }
    ret2[j] = '\0';
    char *new = replace(ret2, target, replacement, 2);
    j = 0;
    while(new[j] != '\0'){
        ret[e] = new[j];
        e++;
        j++;
    }
    return ret;
}

char *replaceAll(char *source, char *pattern, char *replacement)
{
    int len = 0, replacelen = 0, patternlen = 0, idx;
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
    char *ret = malloc((len + replacelen) * sizeof(char));
    char *ret2 = malloc((len + replacelen) * sizeof(char));
    for(idx = 0; idx < i; idx++){
        ret[idx] = source[idx];//copy the first part of source to ret
    }
    for(idx = i; idx - i < replacelen; idx++){
        ret[idx] = replacement[idx - i];//copy the replacement to ret
    }
    int temp = idx;
    j = idx;
    while(source[j - replacelen + patternlen] != '\0'){
        ret2[j-temp] = source[j - replacelen + patternlen];//copy the rest of source to ret2
        j++;
    }
    ret2[j] = '\0';
    char *new = replaceAll(ret2, pattern, replacement);
    while(*new != '\0'){
        ret[idx] = *new;//copy the rest of ret2 to ret
        idx++;
        new++;
    }
    return ret;
}

int mafin() {
    char *source = "Hello, world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!world1world2world3world4world5world!";
    char *target = "world";
    char *replacement = "everyone";
    char *result = replaceAll(source, target, replacement);
    printf("%s", result);
}