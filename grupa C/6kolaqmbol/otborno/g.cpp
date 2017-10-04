#include<cstdio>
#include<iostream>
using namespace std;
void solve()
{
  int a,b,br=1,p;
  scanf("%d%d",&a,&b);
  if(a==b){printf("1\n");return;}
  b/=a;
  for(p=2;p*p<=b&&b>1;p++)
  {
    //cout<<p<<endl;
    while(b>1&&b%p==0){b/=p;br++;}

  }
  if(b==1)printf("%d\n",br);
  else printf("%d\n",br+1);
}
int main()
{
  int t;
  scanf("%d",&t);
  for(; t; --t) solve();
  return 0;
}