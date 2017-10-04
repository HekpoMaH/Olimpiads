#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
int n;
int used[nmax];
int prev[nmax];
int a[nmax],b[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i]>>b[i];
      used[a[i]]++;used[b[i]]++;
      prev[a[i]]=b[i];
   }
   int i;
   for(i=0;i<n;i++){
      if(used[a[i]]==1)break;
   }
   int cur=a[i];
   int t=0;
   int p;
   for(i=1;i<=n;i++){
      cout<<cur<<" ";
      p=cur;
      cur=prev[t];
      t=p;
   }
   cout<<"\n";
}
