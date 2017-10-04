#include<bits/stdc++.h>
using namespace std;
int sg[1000];
int used[1000];
int n;
inline int next(int k){
   memset(used,0,sizeof(used));
   for(int i=1;i<=k;i++){
      if(i==1||i==k)used[sg[k-2]]=1;
      else used[sg[i-2]^sg[k-i-1]]=1;
   }
   for(int i=0;i<=n;i++)if(used[i]==0)
      return i;
   return -1;
}
//void findcycle(){
//   for(int beg=1;beg<=n/2;beg++){
//      for(int sz=2;sz<=n/2;sz++){
//         int fl=1;
//         for(int i=beg+sz;i<=n;i++){
//            if(sg[i]!=sg[i-sz]){
//               fl=0;
//               break;
//            }
//         }
//         if(fl==1){
//            cout<<"found a cycle with beggining "<<beg<<" and lenght "<<sz<<"\n";
//            return;
//         }
//      }
//   }
//}
int main(){
   cin>>n;
   sg[0]=0;
   sg[1]=1;
   for(int i=2;i<=100;i++){
      sg[i]=next(i);
   }
   if(n<=51){
      cout<< (sg[n]==0 ? "Black" : "White") <<"\n";
   }
   else{
      cout<< (sg[52+(n-52)%34]==0 ? "Black" : "White" )<<"\n";
   }
}
