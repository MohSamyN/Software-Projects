#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src.h"

int main()
{
    char in[100] = "";
    char c[100] = "";
    int check;
    int i = 0;
    line a = {"", {"", ""}, "", "", {"", ""}};
    printf(">> ");
    gets(in);
    InputsEntry(&a, in);
    check = InputsCheck(&a);
    if(check != 0)
    {
        while((strcmp(a.fn[i], "")) != 0)
        {
            FileOpen(c, a.fn[i]);
            OptionOper(c, &a, i);
            FileClose(c, a.fn[i]);
            i++;
        }
        printf("Done");
    }
    else
    {
        /* Do Nothing */
    }
    return 0;
}
