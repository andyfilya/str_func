#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_func_puts();
void test_func_strcmp();
void test_func_strlen();
void test_func_strchr();
void test_func_strcpy();
void test_func_strncpy();
void test_func_strdup();
void test_func_strcat();
void test_func_strncat();
void test_func_getline();
void test_func_fgets();

void func_puts(const char *new_str)
{
    assert(new_str);
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
    assert(new_str_1);
    assert(new_str_2);
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
    assert(new_str);
    int strlen = 0;
    for(int j = 0; *(new_str + j) != '\0'; j++)
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
    for(int j = 0; *(str_1 + j) != '\0'; j++)
    {
        str_2[j] = str_1[j];
    }
    char *first = str_2;
    return first;
}
char *new_strncpy(char *str_1, const char *str_2, unsigned int counter)
{
    assert(str_1);
    assert(str_2);
    while(counter--)
    {
        if (*str_2 != '\0')
        {
            *str_1++ = *str_2++;
        }
        else
        {
            *str_1 += '\0';
        }
    }
    char *first = str_1;
    return first;
}
char *new_strdup(const char *str)
{
    assert(str);
    char *new_str;
    int i = 0;
    if (!(new_str = (char *)malloc(sizeof(char) * new_strlen(str) + 1)))
    {
        return NULL;
    }
    while (*str)
    {
        new_str[i++] = *str++;
    }
    new_str[i] = '\0';
    return new_str;
}
void *new_strcat(char *str_1, const char *str_2)
{
    assert(str_1);
    assert(str_2);
    int len_str_1 = new_strlen(str_1);
    for(int i = 0; *(str_2 + i) != '\0'; i++)
    {
        *(str_1 + len_str_1 + i) = *(str_2 + i);
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
        *(str_1 + len_str_1 + i) = *(str_2 + i);
    }
    return str_1;
}
int new_getline(char str[], int counter_of_chars)
{
    int my_char;
    int i = 0;
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
int main()
{
    test_func_puts();
    test_func_strcmp();
    test_func_strlen();
    test_func_strchr();
    test_func_strcpy();
    test_func_strncpy();
    test_func_strdup();
    test_func_strcat();
    test_func_strncat();
    test_func_getline();
    test_func_fgets();
}
void test_func_puts()
{
    char arr[256] = "Andrey123";
    printf("################### Testing new function of program new_puts ##################\n");
    printf("Original puts:"); 
    puts(arr);
    printf("New puts:");
    func_puts(arr);
}

void test_func_strcmp()
{
    printf("################### Testing new function of program new_strcmp ###################\n");
    char str_1[] = "Andrey123";
    char str_2[] = "Andrey456";
    printf("Original strcmp:");
    int num_original = strcmp(str_1, str_2);
    printf("%d\n", num_original);
    printf("New strcmp:");
    int num_new = func_strcmp(str_1, str_2);
    printf("%d\n", num_new);
}

void test_func_strlen()
{
    char str_1[] = "Andrey123";
    printf("################### Testing new function of program new_strlen ###################\n");
    printf("Original strlen:");
    int strlen_original = strlen(str_1);
    printf("%d\n", strlen_original);
    printf("New strlen:");
    int strlen_new = new_strlen(str_1);
    printf("%d\n", strlen_new);
}


void test_func_strchr()
{
    char arr[] = "123wkljdfjnhjqerbfjkl123";
    printf("################### Testing new function of program new_strchr ###################\n");
    char *orig_p = strchr(arr, 'l');
    char *new_p = new_strchr(arr, 'l');
    printf("Original stchr:");
    printf("%d\n", orig_p);
    printf("New strchr:");
    printf("%d\n", new_p);
}

void test_func_strcpy()
{
    char str_1[256] = "Andrey123";
    char str_2[256] = "";
    char str_3[256] = "";
    printf("################### Testing new function of program new_strcpy ###################\n");
    char *orig_p = strcpy(str_1, str_2);
    char *new_p = new_strcpy(str_1, str_3);
    printf("Original strcpy:");
    printf("%s\n", *orig_p);
    printf("New strcpy:"); 
    printf("%s\n", *new_p);
}

void test_func_strncpy()
{
    char str_1[256] = "Andrey123";
    char str_2[256] = "Andy";
    char str_3[256] = "Andrey123";
    char str_4[256] = "Andy";
    printf("################### Testing new function of program new_strncpy ###################\n");
    printf("Original strncpy:");
    strncpy(str_2, str_1, 4);
    printf("%s\n", str_2);
    printf("New strncpy:");
    new_strncpy(str_4, str_3, 4);
    printf("%s\n", str_4);
}

void test_func_strdup()
{
    char str_1[] = "aNDy123";
    printf("################### Testing new function of program new_strdup[] ###################\n");
    char *orig_p = strdup(str_1);
    char *new_p = new_strdup(str_1);
    printf("Original strdup:%s\n", orig_p);
    printf("New strdup:%s\n", new_p);
}

void test_func_strcat()
{
    char str_1[256] = "AnDyFiLyA003";
    char str_2[256] = "AnDyFiLyA003";
    char str_3[256] = "ok";
    printf("################### Testing new function of program new_strcat ###################\n");
    strcat(str_1, str_3);
    printf("Original strcat:%s\n", str_1);
    new_strcat(str_2, str_3);
    printf("New strcat:%s\n", str_2);
}

void test_func_strncat()
{
    printf("################### Testing new function of program new_strncat ###################\n");
    char str_1[256] = "AnDyFiLyA003";
    char str_2[256] = "AnDyFiLyA003";
    char str_3[256] = "ok";
    strncat(str_1, str_3, 1);
    printf("Original strncat:%s\n", str_1);
    new_strncat(str_2, str_3, 1);
    printf("New strncat:%s\n", str_2);
}

void test_func_getline()
{
    char str_2[256] = "fds;lfms;ldlfk";
    int new_num = new_getline(str_2, 8);
    printf("################### Testing new function of program new_getline ###################\n");
    printf("New getline:%d\n", new_num);
}

void test_func_fgets()
{
    printf("################### Testing new function of program new_fgets ###################\n");
    char arr[256] = {0};
    int lim = 256;
    char *p = new_fgets(arr, lim, stdin);
    func_puts(p);
}