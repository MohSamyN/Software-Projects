#ifndef SRC_H_INCLUDED
#define SRC_H_INCLUDED

typedef struct
{
    char rep[20];
    char opt[20][20];
    char from[20];
    char to[20];
    char fn[20][20];
} line;

void InputsEntry(line *p, const char *str);
int InputsCheck(line *p);
void FileOpen(char *c, const char *p);
void OptionOper(char *c, line *p, int i);
void FileClose(char *c, const char *p);

#endif // SRC_H_INCLUDED
