#include<bits/stdc++.h>
using namespace std;
   long long n,m,k;
long long ans(long long a){
   return (n/(a+1)) * (m/(k-a+1));
}
int main(){
   cin>>n>>m>>k;
   if(n-1+m-1<k){
      cout<<-1<<"\n";
      return 0;
   }
   long long x,y;
   x=max(0LL,k+1-m),y=min(k,n-1);
   cout<<max(ans(x),ans(y))<<"\n";
}
