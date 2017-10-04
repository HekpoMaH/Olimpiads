#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
const int nmax=1e6+9;
const int offset=1e5+9;
#define mp make_pair
#define pb push_back
int used[nmax];
int first[nmax];
int last[nmax];
int mx=0;
int x[nmax];
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   memset(first,31,sizeof(first));
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x[i];
      used[x[i]]++;
      mx=max(mx,used[x[i]]);
      first[x[i]]=min(first[x[i]],i);
      last[x[i]]=max(last[x[i]],i);
   }
   int ax=0,ay=n+1;
   for(int i=1;i<=n;i++){
      if(used[x[i]]==mx){
         if(ay-ax+1>last[x[i]]-first[x[i]]+1){
            ax=first[x[i]];
            ay=last[x[i]];
         }
      }
   }
   cout<<ax<<" "<<ay<<"\n";
}
