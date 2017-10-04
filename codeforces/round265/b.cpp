#include<bits/stdc++.h>
using namespace std;
int n;
int a[1009];
int main(){
   cin>>n;

   for(int i=1;i<=n;i++)cin>>a[i];
   int ans=0;
   int first=1;
   for(int i=1;i<=n;i++){
      if(a[i]==1){
         if(a[i]==a[i-1])ans++;
         else if(first){
            ans++;
            first=0;
         }
         else ans+=2;
      }
   }
   cout<<ans<<"\n";
}
