#include<bits/stdc++.h>
using namespace std;
long long n,i,ans,k;
int main(){
  cin>>n;
  i=2;
  k=2;
  while(1){
     if(k>n)
      break;

     if(n%3 == k%3)
        ans++;

     i+=3;
     k+=i;
  }
  cout<<ans<<endl;
}
