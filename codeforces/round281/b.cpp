#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
int n;
vector<int> v1,v2;
lli s1,s2;
string madafaka;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      if(i==1){
         if(x>0)madafaka="second\n";
         else madafaka="first\n";
      }
      if(x>0){
         s1+=x;
         v1.pb(x);
      }
      else{
         x=-x;
         s2+=x;
         v2.pb(x);
      }
   }
   if(s1>s2){
      cout<<"first\n";
      exit(0);
   }
   if(s1<s2){
      cout<<"second\n";
      exit(0);
   }
   for(int i=0;i<min(v1.size(),v2.size());i++){
      if(v1[i]>v2[i]){
         cout<<"first\n";
         exit(0);
      }
      if(v1[i]<v2[i]){
         cout<<"second\n";
         exit(0);
      }
   }
   cout<<madafaka;
}
