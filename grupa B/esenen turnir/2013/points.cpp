#include<bits/stdc++.h>
using namespace std;
const int mod=123456789;
const int nmax=1e4+9;
inline void add(int &a,int b){
   a+=b;
   a%=mod;
}
int n,k;
int b[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int a,first,a1,s=0;
   cin>>n;
   cin>>first;
   a=first;
   for(int i=2;i<=n;i++){
      cin>>a1;
      if(a>a1)s+=(a-a1);
      a=a1;
   }
   k=first-s;
   if(k<0){
      cout<<"0\n";
      return 0;
   }
   for(int i=0;i<=k;i++){
      b[i]=1;
   }
   for(int j=1;j<=n;j++){
      for(int i=1;i<=k;i++){
         add(b[i],b[i-1]);
      }
   }
   cout<<b[k]<<"\n";
}
