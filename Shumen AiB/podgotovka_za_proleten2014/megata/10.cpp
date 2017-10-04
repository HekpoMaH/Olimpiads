#include<iostream>
using namespace std;
void solve(){
   int n,k;
   int a[10009][3];
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i][1]>>a[i][2];
   }
   int br1=0,br2=0;
   for(int i=1;i<=n;i++){
      if(i==k)continue;
      if(a[i][2]==a[k][1])br1++;
      if(a[i][1]==a[k][2])br2++;
   }
   cout<<br1<<" "<<br2<<"\n";
}
int main(){
   int t;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>t;
   while(t--){
      solve();
   }
}
