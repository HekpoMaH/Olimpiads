#include<iostream>
using namespace std;
int proba( int a)
{
  if(a&3)return a>>1;
}

int main()
{
  int a;
  cin>>a;
  if(a&1)cout<<"aa"<<endl;
  proba(a);
  return 0;
}
