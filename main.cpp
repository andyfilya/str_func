#include <stdio.h>


void func_puts(const char *new_str)
{
    int elem = 0;
    while (*(new_str + elem) != '\0')
    {
        printf("%c", *(new_str + elem));
        elem++;
    }
    printf("\n");
}

int func_strcmp(const char *new_str_1, const char *new_str_2)
{
    for (int j = 0; *(new_str_1 + j) != '\0' || *(new_str_2 + j) != '\0'; j++)
    {
        if(*(new_str_1 + j) != *(new_str_2 + j))
        {
            if(*(new_str_1 + j) > *(new_str_2 + j))
            {
                return 1;
            }
            if (*(new_str_1 + j) < *(new_str_2 + j))
            {
                return -1;
            }
        }
        if(*(new_str_1 + j) != '\0' && *(new_str_2 + j) == '\0')
        {
            return 1;
        }
        if (*(new_str_1 + j) == '\0' && *(new_str_2 + j) != '\0')
        {
            return -1;
        }
    }
    return 0;
}


int main()
{
    char str_1[256] = "andreytttttt";
    char str_2[256] = "andreytttt";
    int a = func_strcmp(str_1, str_2);
    printf("%d\n", a);
}