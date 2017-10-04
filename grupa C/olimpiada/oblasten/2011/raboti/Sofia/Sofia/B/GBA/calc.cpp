#include<iostream>
using namespace std;
int main(){
  int n,s,i,a,b,br=0;
  cin>>s>>n;
  while(s>1){
    a=s%n;
    while(a>n){a-=n;br++;}
    if (a){
      s-=a;
      br++;
    }
    s/=n;
    br++;
  }
  cout<<br;
}
