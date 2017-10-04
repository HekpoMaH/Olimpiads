#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
unsigned c,h,n,i,k,l=0,i1,br=0;
double r;
cin>>n;
for(i=1;i<=n;i++)
{
  cin>>k;
  if(k/10==0)l=1;
  else if(k/100==0)l=2;
       else if(k/1000==0)l=3;
            else if(k/10000==0)l=4;
                 else if(k/100000==0)l=5;
                      else if(k/1000000==0)l=6;
  k=k*k;
  for(h=1,i1=1;i1<=l;i1++)
  {
   h=h*10;
   r=k%h;
   c=k/h;
  }
  if(r+c==sqrt(k))br++;
}
cout<<br<<endl;
return 0;
} 
