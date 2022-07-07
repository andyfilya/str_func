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

int new_strlen(const char *new_str)
{
    int strlen = 0;
    for(int j = 0; *(new_str + j) != '\0'; j++)
    {
        strlen++;
    }
    return strlen;
}

char *new_strchr(char *new_str, const char symbol)
{
    for (int j = 0; new_str[j] != '\0'; j++)
    {
        if (new_str[j] == symbol)
        {
            return &new_str[j];
        }
    } 
    return NULL;
}

char *new_strcpy(const char *str_1, char *str_2)
{
    for(int j = 0; *(str_1 + j) != '\0'; j++)
    {
        str_2[j] = str_1[j];
    }
    char *first = str_2;
    return first;
}

int main()
{
    char str_1[256] = "my_name";
    char str_2[256] = "";
    char *new_adress = new_strcpy(str_1, str_2);
    printf("%c", *new_adress);
}