#include<iostream>
using namespace std;
long long a,b,c;
long long mn=1000000000000000000LL,mx;
int main()
{
  cin>>a>>b>>c;
  if(a<mn)mn=a;
  if(b<mn)mn=b;
  if(c<mn)mn=c;
  if(a>mx)mx=a;
  if(b>mx)mx=b;
  if(c>mx)mx=c;//cout<<mn<<" "<<mx<<endl;
  if(a>mn&&a<mx)cout<<a<<endl;
  if(b>mn&&b<mx)cout<<b<<endl;
  if(c>mn&&c<mx)cout<<c<<endl;
  return 0;
}
