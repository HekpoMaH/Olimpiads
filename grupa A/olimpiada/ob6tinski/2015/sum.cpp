#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
int a[nmax];
int used[2009];
int n;
int s;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      if(used[a[i]]==0){
         used[a[i]]=i;
      }
   }
   cin>>s;
   for(int i=1;i<=n;i++){
      int otherNum=s-a[i];
      if(otherNum<=0)continue;
      if(used[otherNum]){
         cout<<i<<" "<<used[otherNum]<<"\n";
         return 0;
      }
   }
   cout<<"0 0\n";
}
