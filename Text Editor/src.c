#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src.h"

static void Backup(const char *c, const char *p);
static void First(char text[100], const char strs[50], const char strr[50]);
static void Last(char text[100], const char strs[50], const char strr[50]);
static void CaseSensitive(char text[100], char strs[50], const char strr[50]);

static int  Alphabet (int alphabet);

void InputsEntry(line *p, const char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(*(str + i) != '\0')
    {
        while((*(str + i) != ' ') && (*(str + i) != '\0'))
        {
            (p -> rep[i]) = *(str + i);
            i++;
        }
        i++;
        while(((*(str + i - 1) != ' ') || (*(str + i) == '-')) && (*(str + i - 1) != '\0'))
        {
            while((*(str + i) != ' ') && (*(str + i) != '\0'))
            {
                (p -> opt[j][k]) = *(str + i);
                i++;
                k++;
            }
            i++;
            j++;
            k = 0;
        }
        j = 0;
        k = 0;
        while((*(str + i) != ' ') && (*(str + i) != '\0'))
        {
            (p -> from[j]) = *(str + i);
            i++;
            j++;
        }
        i++;
        j = 0;
        while((*(str + i) != '\0') && ((*(str + i + 1) != '-') || (*(str + i + 2) != '-')))
        {
            (p -> to[j]) = *(str + i);
            i++;
            j++;
        }
        i += 4;
        j = 0;
        while((*(str + i) != '\0'))
        {
            while((*(str + i) != ' ') && (*(str + i) != '\0'))
            {
                (p -> fn[j][k]) = *(str + i);
                i++;
                k++;
            }
            i++;
            j++;
            k = 0;
        }
        i++;
    }
}

int InputsCheck(line *p)
{
    int i = 0;
    int j = 0;
    int flag = 0;
    int action = 0;
    if(strcmp((p -> rep), "replace") == 0)
    {
        while((strcmp((p -> opt[i]), "") != 0))
        {
            if((strcmp((p -> opt[i]), "-b") == 0))
            {
                flag++;
            }
            else if((strcmp((p -> opt[i]), "-f") == 0))
            {
                flag++;
            }
            else if((strcmp((p -> opt[i]), "-l") == 0))
            {
                flag++;
            }
            else if((strcmp((p -> opt[i]), "-i") == 0))
            {
                flag++;
            }
            else
            {
                /* Do Nothing */
            }
            i++;
        }
        if(i == flag)
        {
            while((strcmp((p -> fn[j]), "") != 0))
            {
                FILE *ft;
                ft = fopen(p -> fn[j], "r");
                if(ft != 0)
                {
                    action = 1;
                }
                else
                {
                    printf("Error in file entry");
                }
                j++;
            }
        }
        else
        {
            printf("Error in operation");
        }
    }
    else
    {
        printf("Error in replace");
    }
    return action;
}

void FileOpen(char *c, const char *p)
{
    FILE *fo;
    int count = 0;
    fo = fopen(p, "r");
    while(feof(fo) == 0)
    {
        c[count] = fgetc(fo);
        count++;
    }
    c[count - 1] = '\0';
    count = 0;
    fclose(fo);
}

void OptionOper(char *c, line *p, int i)
{
    int j = 0;
    while((strcmp((p -> opt[j]), "")) != 0)
    {
        if((strcmp((p -> opt[j]), "-b")) == 0)
        {
            Backup(c, (p -> fn[i]));
        }
        else if((strcmp((p -> opt[j]), "-f")) == 0)
        {
            First(c, (p -> from), (p -> to));
        }
        else if((strcmp((p -> opt[j]), "-l")) == 0)
        {
            Last(c, (p -> from), (p -> to));
        }
        else if((strcmp((p -> opt[j]), "-i")) == 0)
        {
            CaseSensitive(c, (p -> from), (p -> to));
        }
        else
        {
            /* Do Nothing */
        }
        j++;
    }
    j = 0;
}

void FileClose(char *c, const char *p)
{
    FILE *fc;
    fc = fopen(p, "w");
    fprintf(fc, "%s", c);
    fclose(fc);
}

void Backup(const char *c, const char *p)
{
    char file[100] = "";
    FILE *fb;
    sprintf(file, "backup(%s).txt", p);
    fb = fopen(file, "w");
    fprintf(fb, "%s", c);
    fclose(fb);
}

void First(char text[100], const char strs[50], const char strr[50])
{
    char array[10] = "";
    char *save;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m;
    int alphabet = 1;
    int flag = 0;
    int slen = strlen(strs);
    int tlen = strlen(text);
    int strrlen = strlen(strr);
    int alen;
    char *ptext;
    char *ptextbackup;
    ptext = &text[0];
    while((text[i] != '\0') && (flag == 0))
    {
        alphabet = Alphabet(*ptext);
        while((alphabet != 0) && (i <= tlen) && (text[i] != '\0'))
        {
            array[j] = text[i];
            j++;
            i++;
            ptext++;
            alphabet = Alphabet(*ptext);
        }
        j = 0;
        i++;
        ptext++;
        alen = strlen(array);
        if(alen == slen)
        {
            ptext--;
            for(k = 0; k < alen; k++)
            {
                if (array[k] == strs[k])
                {
                    l++;
                }
                else
                {
                    k = alen;
                    l = 0;
                }
            }
            if (l == alen)
            {
                l = 0;
                flag = 1;
                if (strrlen <= slen)
                {
                    ptext = ptext - slen;
                    for( m = 0; m < slen; m++)
                    {
                        if(m < strrlen)
                        {
                            *ptext = strr[m];
                            ptext = ptext + 1;
                        }
                        else if(m < (slen - 1))
                        {
                            ptext = ptext + 1;
                            *ptext = ' ';
                        }
                    }
                    ptextbackup = ptext;
                    for(m = 0 ; m < (slen - strrlen); m++)
                    {
                        while(*ptext != '\0')
                        {
                            *ptext = *(ptext + 1);
                            ptext++;
                        }
                        ptextbackup--;
                        ptext = ptextbackup;
                    }
                    i--;
                }
                else
                {
                    ptextbackup = ptext;
                    ptext = ptext + (tlen - i + 1);
                    save = ptext;
                    for(m = 0 ; m < (strrlen - slen); m++)
                    {
                        while(ptext!= ptextbackup)
                        {
                            *ptext = *(ptext - 1);
                            ptext--;
                        }
                        tlen++;
                        save = save + 1;
                        ptext = save;
                    }
                    ptext = ptextbackup - slen;
                    for( m = 0; m < strrlen; m++)
                    {
                        *ptext = strr[m];
                        ptext = ptext + 1;
                    }
                    ptext++;
                }
            }
            else
            {/**/}
        }
        else
        {/**/}
        for (k = 0; k < alen; k++)
        {
            array[k] = '\0';
        }
    }
}

void Last(char text[100], const char strs[50], const char strr[50])
{
    char array[10] = "";
    char *save;
    char save2;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m;
    int alphabet = 1;
    int slen = strlen(strs);
    int tlen = strlen(text);
    int strrlen = strlen(strr);
    int alen;
    char *ptext;
    char *ptextbackup;
    char *save1;
    ptext = &text[0];
    while(text[i] != '\0')
    {
        alphabet = Alphabet(*ptext);
        while((alphabet != 0) && (i<=tlen) && (text[i] != '\0'))
        {
            array[j] = text[i];
            j++;
            i++;
            ptext++;
            alphabet = Alphabet(*ptext);
        }
        j = 0;
        i++;
        ptext++;
        alen = strlen(array);
        if(alen == slen)
        {
            for(k = 0; k < alen; k++)
            {
                if (array[k] == strs[k])
                {
                    l++;
                }
                else
                {
                    k = alen;
                    l = 0;
                }
            }
            if (l == alen)
            {
                save1 = ptext;
                l = 0;
            }
            else
            {/**/}
        }
        else
        {/**/}
        for (k = 0; k < alen; k++)
        {
            array[k] = '\0';
        }
    }
    if (strrlen <= slen)
    {
        ptext = save1 -1;
        ptext = ptext - slen;
        for( m = 0; m < slen; m++)
        {
            if(m < strrlen)
            {
                *ptext = strr[m];
                ptext = ptext + 1;
            }
            else if(m < slen - 1)
            {
                ptext = ptext + 1;
                *ptext = ' ';
            }
        }
        ptextbackup = ptext;
        for(m = 0 ; m < (slen - strrlen); m++)
        {
            while(*ptext!='\0')
            {
                *ptext = *(ptext + 1);
                ptext++;
            }
            ptextbackup --;
            ptext = ptextbackup;
        }
        i--;
    }
    else
    {
        ptextbackup = ptext;
        ptext = ptextbackup + (tlen -i + 1);
        save = ptext;
        for(m = 0 ; m < (strrlen - slen); m++)
        {
            while(ptext!= ptextbackup)
            {
                *ptext = *(ptext - 1);
                ptext --;
            }
            tlen++;
            save = save + 1;
            ptext = save;
        }
        ptext = ptextbackup - slen -1;
        save2 = *(ptext + slen );
        for( m = 0; m < strrlen; m++)
        {
            *ptext = strr[m];
            ptext = ptext + 1;
            *ptext = save2;
        }
        ptext++;
    }
}

void CaseSensitive(char text[100], char strs[50], const char strr[50])
{
    char array[10] = "";
    char textbackup[500] = "";
    char *save;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m;
    int alphabet = 1;
    int slen = strlen(strs);
    int tlen = strlen(text);
    int strrlen = strlen(strr);
    int alen;
    char *ptext;
    char *ptextbackup;
    ptext = &text[0];
    for(i = 0; i < tlen; i++)
    {
        for(j = 97; j <= 122; j++)
        {
            if((int)(text[i] == j) )
            {
                textbackup[i] = (int)text[i] - 32;
                j= 123;
            }
            else
            {
                textbackup[i] = text[i];
            }
        }
    }
    for(i = 0; i < slen; i++)
    {
        for(j = 97; j <= 122; j++)
        {
            if((int)(strs[i] == j) )
            {
                strs[i] = (int)strs[i] - 32;
                j= 123;
            }
            else{/**/}
        }
    }
    j =0;
    i = 0;
    while(textbackup[i] != '\0')
    {
        alphabet = Alphabet(textbackup[i]);
        while((alphabet != 0) && (i<=tlen) && (textbackup[i] != '\0'))
        {
            array[j] = textbackup[i];
            j++;
            i++;
            ptext++;
            alphabet = Alphabet(textbackup[i]);
        }
        j = 0;
        i++;
        ptext++;
        alen = strlen(array);
        if(alen == slen)
        {
            ptext--;
            for(k = 0; k < alen; k++)
            {
                if (array[k] == strs[k])
                {
                    l++;
                }
                else
                {
                    k = alen;
                    l = 0;
                }
            }
            if (l == alen)
            {
                l = 0;
                if (strrlen <= slen)
                {
                    ptext = ptext - slen;
                    for( m = 0; m < slen; m++)
                    {
                        if(m < strrlen)
                        {
                            *ptext = ' ';
                            *ptext = strr[m];
                            ptext ++;
                        }
                        else if(m < strrlen -1)
                        {
                            ptext = ptext + 1;
                            *ptext = ' ';
                        }
                    }
                    for(m = 0 ; m < (slen - strrlen); m++)
                    {
                        ptextbackup = ptext + 1;
                        while(*ptext!='\0')
                        {
                            *ptext = *(ptext + 1);
                            ptext++;
                        }
                        ptextbackup --;
                        ptext = ptextbackup;
                    }
                    i--;
                }
                else
                {
                    ptextbackup = ptext;
                    ptext = ptext + (tlen -i + 1);
                    save = ptext;
                    for(m = 0 ; m < (strrlen - slen); m++)
                    {
                        while(ptext!= ptextbackup)
                        {
                            *ptext = *(ptext - 1);
                            ptext --;
                        }
                        tlen++;
                        save = save + 1;
                        ptext = save;
                    }
                    ptext = ptextbackup - slen;
                    for( m = 0; m < strrlen; m++)
                    {
                        *ptext = strr[m];
                        ptext = ptext + 1;
                    }
                    ptext++;
                }
            }
            else
            {/**/}
        }
        else
        {/**/}
        for (k = 0; k < alen; k++)
        {
            array[k] = '\0';
        }
    }
}

int  Alphabet(int alphabet)
{
    int i;
    int check = 0;
    for(i = 65 ; i <= 90 ; i++)
    {
        if (alphabet == i)
        {
            check = 1;
            i = 91;
        }
        else {/**/}
    }
    for(i = 97 ; i <= 122 ; i++)
    {
        if (alphabet == i)
        {
            check = 1;
            i = 123;
        }
        else {/**/}
    }
    return check;
}
