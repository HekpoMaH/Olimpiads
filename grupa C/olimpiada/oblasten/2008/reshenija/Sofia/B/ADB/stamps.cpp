#include <iostream>
#include <math.h>
using namespace std;
int main()
{int S,N,b=0,S1=0,br=0;
cin>>S>>N;
if (S<0 || S>5000 || N<0 || N>3000)
cout<<"S ili N ne prenadleji na dopustimite stoinosti"<<endl;
int a[N];
for (int i=0;i<N;i++)
cin>>a[i];
for (int i=0;i<N;i++)
sort (a,a+N);
{   do
    {b=S/a[N];     
     if (b==0)
    { 
      N--;
      b=0;
    } 
     else br=br+b;
     S1=a[N]*b;
     N--;
     }while (S==S1) ;
} 
              




cout<<br<<endl;
return 0;
}
