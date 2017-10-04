#include<bits/stdc++.h>
using namespace std;
int x;
int n;
int cmin=1;
int wt;
int main(){
   cin>>n>>x;
   for(int i=1;i<=n;i++){
      int l,r;
      cin>>l>>r;
      while(cmin+x<=l)cmin+=x;
      wt+=r-cmin+1;
      cmin=r+1;
   }
   cout<<wt<<"\n";
}
