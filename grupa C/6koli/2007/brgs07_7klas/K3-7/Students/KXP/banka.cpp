#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
long long w,ww,q,qq,k,s,a[56],j,n,i,min=-1;
bool p=0;
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
cin>>s;
for(i=1;i<=n;i++)if(!(s%a[i]))
if(min==-1 || min>s/a[i])
{
           p=0;
           w=a[i];
           ww=s/a[i];
           min=s/a[i];
}
for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)
{
for(int f=1;f*a[i]<s;f++)
{
if(!((s-f*a[i])%a[j]) && (min>f+((s-a[i]*f)/a[j]) || min==-1))
{
min=f+((s-a[i]*f)/a[j]);
p=1;
w=a[i];
ww=f;
q=a[j];
qq=(s-a[i]*f)/a[j];
}
}                                 
}
cout<<min<<endl;
if(p)cout<<w<<' '<<ww<<endl<<q<<' '<<qq<<endl;
else cout<<w<<' '<<ww<<endl;
}
