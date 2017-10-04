#include<iostream>
using namespace std;
long long a,b,c,br,brn,n,x;
int main()
{
  cin>>n;
  a=1;b=1;br=2;
  while(1)
  {
    c=a+b;
    a=b;
    b=c;
    br++;//cout<<"brn="<<brn<<endl;
    brn=c-br+2;
    if(brn>=n)
    {
      x=c;//cout<<x<<" "<<brn<<endl;
      while(brn!=n){brn--;x--;}
      cout<<x<<endl;
      break;
    }
  }
  //cout<<x<<endl;
  return 0;
}
