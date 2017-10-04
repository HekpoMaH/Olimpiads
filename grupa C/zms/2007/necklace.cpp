#include<iostream>
using namespace std;
int n,st=1;
int main()
{
  cin>>n;
  for(int i=1;i<n;i++)st*=2;
  if(n%2==1)st--;
  else st++;
  cout<<st/3<<endl;
  return 0;
}
