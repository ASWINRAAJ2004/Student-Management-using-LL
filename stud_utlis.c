#include "student.h"

void read_string(char *str, int size)
{
    int i;

    if (fgets(str, size, stdin) == NULL)
    {
        str[0] = '\0';
        return;
    }

    str[strcspn(str, "\n")] = '\0';

    /* Remove leading spaces */
    i = 0;
    while (isspace((unsigned char)str[i]))
        i++;

    if (i > 0)
        memmove(str, str + i, strlen(str + i) + 1);
}

int read_int(void)
{
    char buffer[100];
    char *end;
    long value;

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        value = strtol(buffer, &end, 10);

        while (isspace((unsigned char)*end))
            end++;

        if (*end == '\0')
            return (int)value;

        printf("Invalid input. Enter an integer: ");
    }
}

float read_float(void)
{
    char buffer[100];
    char *end;
    float value;

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        value = strtof(buffer, &end);

        while (isspace((unsigned char)*end))
            end++;

        if (*end == '\0')
            return value;

        printf("Invalid input. Enter a number: ");
    }
}