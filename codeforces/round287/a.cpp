#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1009];
vector<int> ans;
int n;
int k;
int main(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i].first;
      a[i].second=i;
   }
   sort(a+1,a+n+1);
   int br=0;
   for(int i=1;i<=n;i++){
      if(a[i].first<=k){
         br++;
         k-=a[i].first;
         ans.push_back(a[i].second);
      }
   }
   cout<<br<<"\n";
   for(int i=0;i<br;i++){
      cout<<ans[i]<<" ";
   }
   cout<<"\n";
}
