/*
TASK:odd
LANG:C++
*/
#include <iostream.h>

long int n;
long int v[1000];

void citire ();
void cautare ();

int main ()
{
citire ();
cautare ();
return 0;
}

void citire ()
{
long int i;
long int x;
cin>>n;
for (i=0; i<n; i++)
    {
    cin>>x;
    v[x]++;
    }
}

void cautare ()
{
long int i;
for (i=0; i<1000000; i++)
    if (v[i]%2==1)
       {cout<<i<<'\n'; break;}
}


