#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int  s,n,i,p,w,k=1000000000,j;
int b[10000] ;
void minbar(int p,int T, int m)
{
  int br;
  br=(s-T)/b[p];
  if(m+br<k)
  {
    if(T+br*b[p]==s)k=m+br;
    else
    if(p>=0)
    while(br>=0)
    {
      minbar(p-1,T+br*b[p],m+br);
      br--;
    }
   }
 }
 int main()
{
  cin>>s>>n;
  for(i=0;i<n;i++) cin >>b[i];
  sort(b,b+n);
  //reverse(b.begin(),b.end());
  minbar(n-1,0,0);
  cout<<k<<endl;
}
