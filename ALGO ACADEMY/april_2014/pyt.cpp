#include<bits/stdc++.h>
using namespace std;
long long v1,v2,d,t;
long long ans;
int main(){
   cin>>v1>>v2>>t>>d;
   long long cv=v1;
   for(long long i=1;i<=t;i++){
      //cout<<cv<<"\n";
      ans+=cv;
      long long fl=0;
      for(long long j=d;j>=-d;j--){
         if((cv+j-v2)<=(t-i-1)*d){
            cv+=j,fl=1;
            break;
         }
      }
   }
   cout<<ans<<"\n";
}
