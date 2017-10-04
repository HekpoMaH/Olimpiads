#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

double a[512];
int b[512];
int n,p;

bool complete()
{
    int i;
    for (i=0;i<n;i++)
        if (b[i]!=p-1) return false;
    return true;
}   

bool correct()
{
    int i;
    bool d[512];
    for (i=0;i<p;i++) d[i]=false;
    for (i=0;i<n;i++) d[b[i]]=true;
    for (i=0;i<p;i++) if (d[i]==false) return false;
    return true;
}

int main()
{
    scanf("%d%d",&n,&p);
    int i,j;
    double min=0;
    for (i=0;i<n;i++)
    {
        cin >> a[i];
        min+=a[i];
    }
    min/=(n*p);
    
    printf ("%.3f\n",min);
return 0;
}
