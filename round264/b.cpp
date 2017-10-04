#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int h[nmax];
int n;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   int cur=0,ans=0;;
   for(int i=1;i<=n;i++){
      cin>>h[i];
   }
   int nrj=0;
   for(int i=0;i<n;i++){
      if(nrj-(h[i+1]-h[i])<0){
         ans+=abs(nrj-(h[i+1]-h[i]));
         nrj=0;
      }
      else{
         nrj-=(h[i+1]-h[i]);
      }
   }
   cout<<ans<<"\n";
}
