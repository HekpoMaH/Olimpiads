#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int len;
string needle,s;
int faillink[nmax];
void solve(){
   memset(faillink,0,sizeof(faillink));
   faillink[0]=0;faillink[1]=0;
   for(int i=2;i<=len;i++){
      int j=i;
      j=faillink[i-1];
      for(;;){
         if(needle[i-1]==needle[j]){
            faillink[i]=j+1;
            break;
         }
         if(j==0){
            faillink[i]=0;
            break;
         }
         j=faillink[j];
      }
   }
   int i=0,j=0;
   for(;;){
      if(j==s.size())break;
      if(s[j]==needle[i]){
         i++;
         j++;
         if(i==len){
            cout<<j-len<<"\n";
         }
      }
      else{
         if(i>0)i=faillink[i];
         else j++;
      }
   }
   cout<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   while(cin>>len){
      s="";
      needle="";
      cin>>needle;
      cin>>s;
      solve();
   }
}
