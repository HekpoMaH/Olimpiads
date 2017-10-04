#include<iostream>
using namespace std;
long s,n,sum,d,i,a[3000],j,maxi=99999,br;
int main()
{
    cin>>s>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
sort(a,a+n+1);
for(i=n;i>=1;i--)
 {sum=s;
 d=sum/a[i];
 sum-=a[i]*d;
br+=d;
 for(j=i;j>=1;j--)
  {
   d=sum/a[j];
   sum-=d*a[j];                 
      br+=d;              
  }
if(br<maxi)maxi=br;
}
cout<<maxi<<endl;
//system("pause");    
return 0;
}
