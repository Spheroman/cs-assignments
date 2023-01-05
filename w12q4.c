/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base and store the result as a string in result
return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/
char *convertToDifferentBase(int dec, int base, char *result) {
    int i = 0;
    while(dec != 0){
        int temp = dec % base;
        if(temp < 10){
            result[i] = temp + '0';
        }
        else{
            result[i] = temp - 10 + 'A';
        }
        dec /= base;
        i++;
    }
    result[i] = '\0';
    int j = 0;
    i--;
    while(j < i){
        char temp = result[j];
        result[j] = result[i];
        result[i] = temp;
        j++;
        i--;
    }
    return result;
}
