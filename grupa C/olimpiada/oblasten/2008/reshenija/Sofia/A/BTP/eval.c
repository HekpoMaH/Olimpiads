#include <stdio.h>
#include <string.h>

int main()
{
    int br=0;
    char ss[32];
    scanf("%s",ss);
    int i;
    for (i=0;i<strlen(ss);++i) if (ss[i] == '(') ++br;
    if (br == 0) br = 1;
    printf("%d\n",br);
    return 0;
}
