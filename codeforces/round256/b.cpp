#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int used[nmax];
int used2[nmax];
int a,b,medals,cups;
string s,t;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s>>t;
   for(int i=0;i<s.size();i++){
      used[s[i]-'a']++;
   }
   for(int i=0;i<t.size();i++){
      used2[t[i]-'a']++;
   }
   int atm=0,arr=1,nt=0;
   for(int i=0;i<26;i++){
      if(used[i]<used2[i]){nt=1;break;}
      if(used[i]>used2[i]){atm=1;}
   }
   if(nt==1){
      cout<<"need tree"<<'\n';
      return 0;
   }
   int uk=0;
   for(int i=0;i<s.size();i++){
      if(s[i]==t[uk]){
         uk++;
      }
      if(uk==t.size())arr=0;
   }
   if(arr==1&&atm==1)cout<<"both\n";
   if(arr==1&&atm==0)cout<<"array\n";
   if(arr==0&&atm==1)cout<<"automaton\n";

}
