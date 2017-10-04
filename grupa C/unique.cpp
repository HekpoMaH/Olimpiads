#include<iostream>
#include<string>
using namespace std;
string a,b;
long long a1,b1;
int used[10];
int perm(long long num)
{
  if(num>b1)return 0;
  long long otg;
  otg=(num>=a1&&num<=b1);
  for(int i=!num;i<10;i++)
  {
    if(used[i]==0)
    {
      used[i]=1;
      otg+=perm(num*10+i);
      used[i]=0;
    }
  }
  return otg;
}
int main()
{
  cin>>a>>b;
  if(a.size()>10)a1=10000000000LL;
  else for(int i=0;i<a.size();i++)a1=a1*10+a[i]-'0';
  if(b.size()>10)b1=10000000000LL;
  else for(int i=0;i<b.size();i++)b1=b1*10+b[i]-'0';
  //cout<<a1<<" "<<b1<<endl;
  cout<<perm(0)<<endl;
}
