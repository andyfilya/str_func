#include "head.h"

void func_puts(const char *new_str)
{
    assert(new_str);
    int elem = 0;
    while (new_str[elem] != '\0')
    {
        printf("%c", *(new_str + elem));
        elem++;
    }
    printf("\n");
}

int func_strcmp(const char *new_str_1, const char *new_str_2)
{
    assert(new_str_1);
    assert(new_str_2);

    for (int j = 0; new_str_1[j] != '\0' || new_str_2[j] != '\0'; ++j)
    {
        if(new_str_1[j] != new_str_2[j])
        {
            if(new_str_1[j] > new_str_2[j])
            {
                return 1;
            }
            if (new_str_1[j] < new_str_2[j])
            {
                return -1;
            }
        }
        if(new_str_1[j] != '\0' && new_str_2[j] == '\0')
        {
            return 1;
        }
        if (new_str_1[j] == '\0' && new_str_2[j] != '\0')
        {
            return -1;
        }
    }

    return 0;
}

int new_strlen(const char *new_str)
{
    assert(new_str);

    int strlen = 0;

    for(int j = 0; new_str[j] != '\0'; j++)
    {
        strlen++;
    }

    return strlen;
}

char *new_strchr(char *new_str, const char symbol)
{
    assert(new_str);
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
    assert(str_1);
    assert(str_2);

    for(int j = 0; str_1[j] != '\0'; j++)
    {
        str_2[j] = str_1[j];
    }

    return str_2;
}

char *new_strncpy(char *str_1, const char *str_2, unsigned int counter)
{
    assert(str_1);
    assert(str_2);
    
    int j = 0;

    while(counter-- && str_1[j] != '\0' && str_2[j] != '\0')
    {
        if (*str_2 != '\0')
        {
            str_1[j] = str_2[j];
            ++j;
        }
        else
        {
            *str_1 += '\0';
        }
    }

    return str_1;
}

char *new_strdup(const char *str)
{
    assert(str);

    char *new_str = nullptr;
    int i = 0;

    if (!(new_str = (char *)malloc(sizeof(char) * new_strlen(str) + 1)))
    {
        return NULL;
    }
    while (*str && str[i] != '\0' && str[i] != '\0')
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    
    return new_str;
}
void *new_strcat(char *str_1, const char *str_2)
{
    assert(str_1);
    assert(str_2);

    int len_str_1 = new_strlen(str_1);

    for(int i = 0; str_2[i] != '\0'; i++)
    {
        str_1[len_str_1 + i] = str_2[i];
    }

    return str_1;
}
void *new_strncat(char *str_1, char *str_2, int counter_of_chars)
{
    assert(str_1);
    assert(str_2);

    int len_str_1 = new_strlen(str_1);

    for(int i = 0; i < counter_of_chars; i++)
    {
        str_1[len_str_1 + i] = str_2[i];
    }

    return str_1;
}
int new_getline(char str[], int counter_of_chars)
{
    int my_char = NULL, i = 0;

    for(i = 0; i < counter_of_chars && (my_char = getchar()) != EOF && my_char != '\n'; i++)
    {
        str[i] = my_char;
        if (my_char == '\n')
        {
            str[i] = my_char;
            i++;
        }
        str[i] = '\0';
    }
    return i;
}
char *new_fgets(char *str, int lim, FILE *iop)
{
    assert(str);
    int c;
    char *cs;
    cs = str;
    while(--lim > 0 && (c = getc(iop)) != EOF)
    {
        if ((*cs++ = c) == '\n')
        {
            break;
        }
    }
    *cs = '\0';
    return (c == EOF && cs == str) ? NULL : str;
}