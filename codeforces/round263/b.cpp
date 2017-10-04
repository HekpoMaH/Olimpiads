#include<bits/stdc++.h>
using namespace std;
long long used[69];
long long n,k;
string s;
int main(){
   cin>>n>>k;
   cin>>s;
   for(int i=0;i<n;i++){
      used[s[i]-'A']++;
   }
   sort(used,used+26);
   reverse(used,used+26);
   long long ans=0;
   
   for(int i=0;i<26;i++){
      if(k>=used[i]){
         ans+=used[i]*used[i];
         k-=used[i];
      }
      if(k<used[i]){
         ans+=k*k;
         break;
      }
   }
   cout<<ans<<"\n";
}
