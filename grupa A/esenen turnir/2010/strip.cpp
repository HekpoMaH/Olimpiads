#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const lli nmax=10009;
lli a[nmax],n,k;
void fold(lli start){
   lli t=a[start];
   if(t==0||t==n)return;
   if(t<=(n>>1)){
      for(int i=start;i<k;i++){
         if(a[i]<=t)a[i]=t-a[i];
         else a[i]-=t;
      }
      n-=t;
   }
   else{
      for(int i=start;i<k;i++){
         if(a[i]>t)a[i]=2*t-a[i];
      }
      n=t;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=0;i<k;i++){
      cin>>a[i];
   }
   for(int i=0;i<k;i++){
      if(n==1)break;
      fold(i);
   }
   cout<<n<<"\n";
}
