#include<bits/stdc++.h>
using namespace std;
string s[50]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main(){
   string giv;
   int n;
   cin>>n;
   cin>>giv;
   for(int i=0;i<8;i++){
      int l=0;
      if(giv.size()!=s[i].size())continue;
      for(int j=0;j<giv.size();j++){
         if(giv[j]!='.'){
            if(giv[j]!=s[i][j]){
               l=1;
               //cout<<i<<"th differ at pos "<<j<<" "<<giv[j]<<" "<<s[i][j]<<"\n";
               break;
            }
         }
      }
      if(l==0){
         cout<<s[i]<<"\n";
         return 0;
      }
   }
}
