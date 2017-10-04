/*
TASK:METRO
LANG:C++
*/
#include <iostream.h>

int n;
long int suma, crt;
int v[1000];

void citire ();
void obama ();
void afisare ();

int main ()
{
citire ();
obama ();
afisare ();
return 0;
}

void citire ()
{
int i, x;
cin>>n;
for (i=0; i<n; i++)
    {cin>>x; v[i]=x; crt+=x;}
crt/=n;
}

void obama ()
{
int i, ok=0, lg=0;
for (i=0; i<n; i++)
    {
    if (v[i]>crt)
       { if (ok==0) lg++; else if (ok==1) {suma+=1; ok=0; lg=0;} else {suma+=lg*7; lg=0; ok=0;} }
       else
       if (v[i]==crt)
          {if (ok==1)  suma+=1; else if (ok==0) {suma+=lg*lg; lg=0; ok=1;} else {suma+=lg*7; lg=0; if (v[i-1]>v[i]) ok=1; else ok=0;} }
          else
          {if (ok==0)  {suma+=lg*lg; lg=0; ok=2;} else if (ok==1) {suma+=1; lg=0; ok=1;} else lg++; }
    if (i==n-1)
       if (ok==0)
          suma+=lg*lg;
          else
          if (ok==1)
             suma+=1;
             else
             suma+=lg*7;
    }
}

void afisare ()
{
cout<<suma<<'\n';
}