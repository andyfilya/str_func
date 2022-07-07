#include <stdio.h>
void func_puts(const char *new_str)
{
    int i = 0;
    while (*(new_str + i) != '\0')
    {
        printf("%c", *(new_str + (i)));
        i++;
    }
    printf("\n");
}
int main()
{
    char str[256] = "my_name";
    func_puts(str);
}