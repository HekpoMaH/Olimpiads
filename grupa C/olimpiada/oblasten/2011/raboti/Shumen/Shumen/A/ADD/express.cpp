#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s;
long long a[16],n,n1,ok1,ok2;
char b[16];
int main()
{
 int i;
 cin>>s;
 n1=s.size();
 for(i=0;i<n1;i++)
  if(i%2)
  {
   b[n]=s[i];
  }
  else
  {
   a[++n]=s[i]-'0';
  }
 ok1=a[n];
 for(i=n-1;i>0;i--)
 {
  if(b[i]=='+')
  {
   ok1=a[i]+ok1;
  }
  else
   if(b[i]=='-')
   {
    ok1=a[i]-ok1;
   }
   else
   {
    ok1=a[i]*ok1;
   }
 }
 ok2=a[1];
 for(i=2;i<=n;i++)
 {
  if(b[i-1]=='+')
  {
   ok2=ok2+a[i];
  }
  else
   if(b[i-1]=='-')
   {
    ok2=ok2-a[i];
   }
   else
   {
    ok2=ok2*a[i];
   }
 }
 //printf("%I64d %I64d\n",ok1,ok2);
 printf("%lld\n",min(ok1,ok2));
 return 0;
}
