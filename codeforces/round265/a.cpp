#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int n;
string s;
string s2;
int main(){
   cin>>n;
   cin>>s;
   int naum=1;
   for(int i=0;i<n;i++){
      if(naum==1){
         s2+=(char)(s[i]+1);
         naum=0;

         if(i!=0&&s[i]=='1')s2[i-1]='0';
         
         if(s2[i]=='2'){
            s2[i]='0';
            naum=1;
         }
      }
      else s2+=s[i];

   }
   int ans=0;
   for(int i=0;i<n;i++)if(s[i]!=s2[i])ans++;
   cout<<ans<<"\n";
}
