#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int a[nmax];
int n,k;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   sort(a+1,a+n+1);
   reverse(a+1,a+n+1);
   long long sum=0,prof=0;
   for(int i=k;i<=n;i+=k){
      prof+=a[i];
   }
   for(int i=1;i<=n;i++){
      sum+=a[i];
   }
   cout<<sum-prof<<"\n";
}
