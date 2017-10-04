#include<bits/stdc++.h>
using namespace std;
string s[55];
int n,m;
map<char,int> mp;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>s[i];
   }
   int br=0;
   for(int is=0;is<n-1;is++){
      for(int js=0;js<m-1;js++){
         mp.clear();
         mp[s[is][js]]++;
         mp[s[is+1][js]]++;
         mp[s[is][js+1]]++;
         mp[s[is+1][js+1]]++;
         if(mp['f']==1&&mp['a']==1&&mp['c']==1&&mp['e']==1)br++;
      }
   }
   cout<<br<<"\n";
}
