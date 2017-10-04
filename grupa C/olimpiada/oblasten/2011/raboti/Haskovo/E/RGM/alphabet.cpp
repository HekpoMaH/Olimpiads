#include <iostream>
using namespace std;
int main ()
{
char b2;
int n,m,r,br=0,br1=0,b3,b1,ch,p;
cin>>n>>m;
b1=('a'+n)-1;
b3=('A'+n)-1;
for (int i=1; i<=m; i++)
{
  do
  {
  br++;
  cin>>b2;
  if (b2==b1 && br==1 && br1==0 || b2==b3 && br==1 && br1==0) {r=i; br1++;}
  }
  while (b2!='.');
  br=0;
}
if (br1>0) {cout<<"win"<<" "<<r<<endl;}
else {cout<<"lose"<<endl;}
  return 0;
}