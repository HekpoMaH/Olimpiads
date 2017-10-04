/*
TASK:names
LANG:C++
*/

/* ID: Alexander Georgiev */
#include <cstdio>
#include <cstring>
#define MAX 32

using namespace std;
FILE *in; FILE *out;


int main(void)
{
int i, n;
char name[MAX]; int cnt;
char curname[MAX];

memset(name, 0, sizeof(name)); cnt = 0;

scanf("%d\n", &n);
//gets(curname);
for (i=0; i<n; i++)
{
    gets(curname);
    if (cnt == 0) {memcpy(name, curname, MAX); cnt = 1; continue;}
    
    if (!strcmp(curname, name)) cnt++;
    else cnt--;
    }

printf("%s\n", name);
return 0;
}
