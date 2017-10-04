/*
TASK:money
LANG:C++
*/

#include <iostream.h>


long int max, maxim, n, v[1000];
int x[1000];

void citire ();
void barrack ();
void afisare ();

int main ()
{
citire ();
barrack ();
afisare ();
return 0;
}

void citire ()
{
long int i;
cin>>n;
for (i=0; i<n; i++)
    cin>>v[i];
}

void barrack ()
{
long int i, nr, suma, nrzero;
int ok=0;
while (ok==0)
      {
      ok=1;
      for (i=n-1; i>=0; i--)
          if (x[i]==0)
             {
             ok=0;
             x[i]++;
             break;
             }
             else
             {
             x[i]=0;
             }
      if (i==-1)
      suma=0;
      maxim=0;
      nr=0;
      nrzero=0;
      for (i=0; i<n; i++)
          if (x[i]==0)
             {
             nrzero++;
             if (v[i]>maxim)
                 maxim=v[i];
             }
             else
             {suma+=v[i]; nr++;}
      if (suma>maxim&&nr>max&&nrzero>=2)
         max=nr;
      }
}

void afisare ()
{
cout<<max<<'\n';
}
