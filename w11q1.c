char *mystrcat(char *dest, char *src)
{
    char *end = dest;
    while (*end != '\0')
        end++;
    while (*src != '\0')
        *end++ = *src++;
    *end = '\0';
    return dest;
}

char *mystrncat(char *dest, char *src, int n)
{
    char *end = dest;
    while (*end != '\0')
        end++;
    while (*src != '\0' && n > 0)
    {
        *end++ = *src++;
        n--;
    }
    *end = '\0';
    return dest;
}