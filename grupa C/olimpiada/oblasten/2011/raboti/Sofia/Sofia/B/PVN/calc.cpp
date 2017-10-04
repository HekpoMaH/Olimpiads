#include<iostream>
using namespace std;
int main()
{
  long long s,n,br=0;
  cin>>s>>n;
  while(s!=0) {
    if(s%n==0) {
      if(s==n) {
        s=0;
      }
      else {
        s=s/n;
      }
    }
    else {
      s=s-(s%n);
    }
    br++;
  }
  cout<<br<<endl;
  return 0;
}