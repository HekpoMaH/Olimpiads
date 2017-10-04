#include<bits/stdc++.h>
using namespace std;
const int nmax=3*1e5+9;
long long psum[nmax];
int a[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cerr<<nmax<<"\n";
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++){
      psum[i]=(long long)a[i]+psum[i-1];
   }
   unsigned long long ans=0;
   ans+=psum[n];
   for(int i=1;i<n;i++){
      ans+=psum[n]-psum[i-1];
   }
   cout<<ans<<endl;
}
