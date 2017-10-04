/*
TASK:DIET
LANG:C++
*/
#include <iostream.h>

long int zile, taieturi;
long int g1, g2, g3;

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
cin>>g1>>g2>>g3;
}

void obama ()
{
long int i;
zile=(g1*10+g2*20+g3*30)/60;
if (g1<g2&&g1<g3)
   {g2-=g1; g3-=g1; i=g1+1; g1=0;}
   else
   if (g2<g1&&g2<g3)
      {g1-=g2; g3-=g2; i=g2+1; g2=0;}
      else
      {g1-=g3; g2-=g3; i=g3+1; g3=0;}
for (; i<=zile; i++)
    {
    if (g1!=0)
        g1--;
        else
        if (g2!=0)
           {g2--; g1++; taieturi++;}
           else
           if (g3!=0)
              {g3--; g2++; taieturi++;}
              else break;
    if (g2!=0)
       g2--;
       else
       if (g1>1)
          {g1-=2;}
          else
          if (g3!=0)
             {g3--; g1++; taieturi++;}
             else break;
    if (g3!=0)
       g3--;
       else
       if (g2!=0&&g1!=0)
          {g2--; g1--;}
          else
          if (g2>1)
             {g2-=2; taieturi++; g1++;}
             else
             if (g1>2)
                {g1-=3;}
                else break;
    }
}

void afisare ()
{
cout<<zile<<' '<<taieturi<<'\n';
}