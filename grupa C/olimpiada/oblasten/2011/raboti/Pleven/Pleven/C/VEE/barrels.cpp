#include<iostream>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

long a[100000099],n,s,i,c,fl,fl1,j;

int main()
{
    cin>>s>>n;
    for(i=1;i<=n;i++)
    {
      cin>>c;
      a[c]=1;
      if(s==c)fl1=1;
      if(c*2<s)a[c*2]=2;
      if(c*2==s){a[c*2]=2;fl1=1;}
    }
    if(fl1==0)
       for(i=1;i<=s;i++)
       {
         fl=0;
         if(a[i]==0)
         for(j=1;j<=i/2;j++)
         {
           if(fl==0){a[i]=a[j]+a[i-j];fl=1;}
           else
           a[i]=min(a[j]+a[i-j],a[i]);
         }
       }
    cout<<a[s]<<endl;
    return 0;
}
// 10000 7 12 1 11 30 14 2 18
