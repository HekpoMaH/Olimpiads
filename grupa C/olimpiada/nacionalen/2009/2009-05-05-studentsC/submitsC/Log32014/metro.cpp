/*
TASK:metro
LANG:C++
*/
#include<iostream>
#include<vector>
using namespace std;
vector <long> a;
long n,m,i,minc=100001;
void metro (long i, long cash)
{
   if (i==n-1) {if (cash<minc) {minc=cash;} return;}
   for(long j=a[i]-3;j<=a[i]+3;j++)
   {
      if (j>a[i]) {cash=cash+7*(j-a[i]);}
      if (j==a[i]) {cash++;}
      if (j<a[i]) {cash=cash+(a[i]-j)*(a[i]-j);}
      metro (i+1, cash);
   }   
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
       cin>>m;
       a.push_back(m);
    }
    metro (0,0);
    cout<<minc<<endl;
    //system("pause");
    return 0;
}
