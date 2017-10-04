/*
TASK:ship
LANG:C++
*/

#include <iostream.h>


long int n, v[1000], poz[1000], crt[1000];
long int suma;

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
int i;
cin>>n;
for (i=0; i<n; i++)
    crt[i]=i;
for (i=0; i<n; i++)
    cin>>v[i];
for (i=0; i<n; i++)
    cin>>poz[i];
}

void barrack ()
{
long int i, poz_crt;
long int x=0, y=1, aux, aux2;
for (i=0; i<n; i++)
    if (crt[i]!=poz[i])
       {
       poz_crt=i;
       x=poz[i];
       y=poz[x];
       aux=v[i];
       aux2=v[x];
       suma+=1;
       suma-=1;
       while (x!=crt[y])
             {
             poz[x]=x;
             if (x!=crt[y])
                suma+=v[poz_crt]+v[x];
                else
                suma+=v[x];
             v[x]=aux;
             aux=aux2;
             poz_crt=x;
             x=y;
             aux2=v[x];
             y=poz[x];
             }
       }
}

void afisare ()
{
cout<<suma<<'\n';
}
