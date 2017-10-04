#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[4];
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      v[x].push_back(i);
   }
   int ans=min(min(v[1].size(),v[2].size()),v[3].size());
   cout<<min(min(v[1].size(),v[2].size()),v[3].size())<<"\n";
   for(int i=0;i<ans;i++){
      cout<<v[1][i]<<" "<<v[2][i]<<" "<<v[3][i]<<"\n";
   }
}
