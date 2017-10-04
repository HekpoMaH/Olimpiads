#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5;
pair<int,int> a[nmax];
int main(){
   int n;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      a[i]=make_pair(x,y);
   }
   sort(a+1,a+n+1);
   int mx=0;
   for(int i=1;i<=n;i++){
      if(a[i].second<mx){
         cout<<"Happy Alex\n";
         return 0;
      }
      mx=max(a[i].second,mx);
   }
   cout<<"Poor Alex\n";
}
