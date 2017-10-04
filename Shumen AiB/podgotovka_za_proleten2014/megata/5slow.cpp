#include<iostream>
using namespace std;
int n,k;
int mimimal;
void solve(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      if(3*(k+i)>=(n+i)){
         cout<<i<<"\n";
         return;
      }
   }
}
int main(){
   int t;
   cin>>t;
   while(t--)solve();
}
