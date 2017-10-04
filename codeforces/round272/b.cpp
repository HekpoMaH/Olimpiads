#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long lli;
string s1,s2;
int br1,br2;
int cpos=0;
void go(int curpos,int nc){
   if(nc==s2.size()){
      if(curpos==cpos)br1++;
      br2++;
      return;
   }
   if(s2[nc]=='+'){
      go(curpos+1,nc+1);
      return;
   }
   if(s2[nc]=='-'){
      go(curpos-1,nc+1);
      return;
   }
   else{
      go(curpos+1,nc+1);
      go(curpos-1,nc+1);
   }
}
int main(){
   cin>>s1;
   cin>>s2;
   for(int i=0;i<s1.size();i++){
      if(s1[i]=='+')cpos++;
      else cpos--;
   }
   go(0,0);
   cout<<setiosflags(ios::fixed)<<setprecision(9)<<(double)br1/(double)br2<<"\n";
}
