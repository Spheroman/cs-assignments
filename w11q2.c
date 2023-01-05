char *trim(char *dest)
{
    char *start = dest;
    while (*start == '\n' || *start == '\t' || *start == ' ')
        start++;
    char *end = start;
    while (*end != '\0')
        end++;
    end--;
    while (*end == '\n' || *end == '\t' || *end == ' ')
        end--;
    char *result = dest;
    while (start <= end)
        *result++ = *start++;
    *result = '\0';
    return dest;
}