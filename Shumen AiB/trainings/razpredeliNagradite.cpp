//informatics - 486
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int n,k,x;
int main(){
   cin>>n>>k;
   x=n/k;
   if(n==1&&k==1){
      cout<<1<<"\n";
   }
   else if(x<=1||(n%k!=0)){
      cout<<0<<"\n";
   }
   else{
      if(!(x&1)){
         for(int i=1;i<=k;i++){
            for(int j=1;j<=x;j++){
               if(!(j&1)){
                  cout<<i+(j-1)*k<<" ";
               }
               else{
                  cout<<k-i+1+(j-1)*k<<" ";
               }
            }
            cout<<"\n";
         }
      }
      else{
         if(!(k&1)){
            cout<<0<<"\n";
         }
         else{
            for(int i=1;i<=k;i++){
               cout<<i<<" "<<k+(i+k/2)%k+1<<" "<<3*(3*k+1)/2-i-(k+(i+k/2)%k+1)<<" ";
               for(int j=4;j<=x;j++){
                  if(!(j&1)){
                     cout<<i+(j-1)*k<<" ";
                  }
                  else{
                     cout<<k-i+1+(j-1)*k<<" ";
                  }
               }
               cout<<"\n";
            }
         }
      }
   }
}
