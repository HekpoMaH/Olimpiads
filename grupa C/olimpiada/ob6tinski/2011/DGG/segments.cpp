#include<iostream>
using namespace std;
int ots[204];
int a,b,c,d,br=-1,r;
int main()
{
  cin>>a>>b>>c>>d;
  if(a>b){r=a;a=b;b=r;}
  if(c>d){r=c;c=d;d=r;}
  for(int i=a+100;i<=b+100;i++)ots[i]++;
  for(int i=c+100;i<=d+100;i++)ots[i]++;
  for(int i=0;i<=200;i++)if(ots[i]==2)br++;
  cout<<br<<endl;
  return 0;
}
