#include <stdio.h>
#include <string.h>

char a[26];
char b[27];

int list[30];
int li;

void list_push(int c)
{
    *(list + li) = c;
    li++;
}

int list_pull()
{
    li--;
    return (*(list + li));
}

//priority
// 0 = none
// 1 = + -
// 2 = * /
// 3 = ^

void simplify()
{
    int ai = 0, bi = 0;
    int p = 0;
    int t;

    while (1)
    {
        t = *(a + ai);
        if (t == '\0') break;

        if (t == '(')
        {
            *(b + bi) = t;
            bi++;

            list_push(p);
            p = 0;
        }
        else if (t == ')')
        {
            *(b + bi) = t;
            bi++;

            p = list_pull();
        }
        else if (t == '^')
        {
            if (p == 0) p = 3;
            while (p < 3)
            {
                *(b + bi) = '(';
                bi++;

                list_push(p);
                p++;
            }
            *(b + bi) = t;
            bi++;
        }
        else if ((t == '*') || (t == '/'))
        {
            if (p == 0) p = 2;
            if (p < 2)
            {
                *(b + bi) = '(';
                bi++;

                list_push(p);
                p++;
            }
            else if (p > 2)
            {
                *(b + bi) = ')';
                bi++;

                p = list_pull();
            }
            *(b + bi) = t;
            bi++;
        }
        else if ((t == '+') || (t == '-'))
        {
            if (p == 0) p = 1;
            while (p > 1)
            {
                *(b + bi) = ')';
                bi++;

                p = list_pull();
            }
            *(b + bi) = t;
            bi++;
        }

        ai++;
    }
    *(b + bi) = ')';
    *(b + bi + 1) = '\0';
}

int ways(int* f)
{
    int c = 0;
    char t;
    int i = *f;
    int ec = 0, ew = 1;
    char last = '\0';

    while (1)
    {
        t = *(b + i);
        if (t == '(')
        {
            *f = i + 1;
            ec++;
            ew *= ways(f);
            i = *f;
        }
        else if (t == ')')
        {
            if (ec == 0) ec = 1;
            *f = i;
            return ((ec * ew) * c);
        }
        else if (t == '^')
        {
            c = 1;
            last = t;
        }
        else if ((t == '*') || (t == '+'))
        {
            if (last == '\0') c++;
            else
            {
                if ((last == '*') || (last == '+')) c++;
            }
            last = t;
        }
        else if ((t == '/') || (t == '-'))
        {
            if (last == '\0') c++;
            else
            {
                if ((last == '*') || (last == '+')) c++;
            }
            last = t;
        }
        i++;
    }
}

int main(int argc, char* argv[])
{
    int o = 0;

    li = 0;

    scanf("%s", a);
    simplify();
    printf("%s\n", b);
    printf("%d", ways(&o));
    scanf("%s", a);

    return (0);
}
