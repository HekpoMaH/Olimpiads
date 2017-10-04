#include<iostream>
using namespace std;
int main()
{
  long long int n,k,l,d,newd,oldd,brd,b=0,c,newd2,br=1,i,j,f,newb=0,l1;
  cin>>n;
  for(i=1;i<=n;i++)
  {
  cin>>k;
  c=k;
  oldd=k;
   do
  {
    oldd/=10;
    j++;
  }
  while(oldd!=0);
  if(j%2==0){l=j/2;l1=l;}
  else
  {l=(j+1)/2;l1=l-1;}
  d=k*k;
  for(f=1;f<=l;f++)
  {
    b*=10;
    b+=(d%10);
    d/=10;
  }
  do
    {
     newb*=10;
     newb+=(b%10);
     b/=10;
   }
   while(b!=0);
  if((newb+d)==c)br++;
    }

cout<<br<<endl;
return 0;
}
