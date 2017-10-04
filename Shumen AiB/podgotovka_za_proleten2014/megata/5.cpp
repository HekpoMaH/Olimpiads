#include<iostream>
#include<cmath>
using namespace std;
int n,k;
int mimimal;
void solve(){
   cin>>n>>k;
   cout<<max(0,(int)(ceil((double)(n-3*k)/2.0)))<<"\n";
}
int main(){
   int t;
   cin>>t;
   while(t--)solve();
}
