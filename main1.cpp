#include <stdio.h>


int putsss (const char* stroka);


int main()
{
    char stroka [] = "tilt";

    putsss (stroka);

    return 0;
}

int putsss (const char* stroka)
{
    int index = 0;
    for (;stroka[index] != '\0'; ++index);
    {
        putc(stroka[index], stdout);
    }
    putc ('\n', stdout);

    return 0;
}
