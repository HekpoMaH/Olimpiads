#include<iostream>
using namespace std;
void solve(){
   int n,br=0,k;
   cin>>n>>k;
   while(n>0){
      n-=k;
      k++;
      br++;
   }
   cout<<br<<"\n";
}
int main(){
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
