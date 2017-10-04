#include<bits/stdc++.h>
using namespace std;
const int nmax=5*1e5+9;
int b[9];
int arr[nmax];
int arr2[nmax];
int sum,uarr;
void read(){
   for(int i=1;i<=5;i++)cin>>b[i];
   for(int i=1;i<=5;i++){
      for(int j=1;j<=b[i];j++){
         arr[++uarr]=i;
      }
      sum+=b[i];
   }
   //for(int i=1;i<=uarr;i++){
   //   cerr<<arr[i]<<" ";
   //}
   //cerr<<"\n";
}
void solve(){
   int u1=1,u2=uarr;
   int uk1=1,uk2=sum;
   while(uk1<=uk2){
      arr2[uk1]=arr[u2];
      u2--;uk1++;

      if(uk1<=uk2){
         arr2[uk1]=arr[u1];
         u1++;uk1++;
      }

      arr2[uk2]=arr[u2];
      u2--;uk2--;

      if(uk1<=uk2){
         arr2[uk2]=arr[u1];
         u1++;uk2--;
      }
   }
   int ans=0;
   //for(int i=1;i<=sum;i++){
   //   cerr<<arr2[i]<<" ";
   //}
   //cerr<<"\n";
   for(int i=1;i<sum;i++){
      ans+=max(abs(arr2[i]+arr2[i+1])-5,0);
   }
   cout<<ans<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
