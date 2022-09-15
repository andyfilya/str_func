#include "head.h"

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

