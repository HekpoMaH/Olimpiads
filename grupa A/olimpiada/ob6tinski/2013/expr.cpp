#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
   cin>>s;
   int op1,op2,hb;
   for(int i=0;i<s.size();i++){
      if(s[i]=='('){
         if(op1==1){
            cout<<"0\n";
            return;
         }
         op1=1;
      }
      if(s[i]==')'){
         if(op1==0){
            cout<<"0\n";
            return;;
         }
         hb=1;
         op1=0;
      }
      if(s[i]=='['){
         if(op1==1){
            cout<<"0\n";
            return;;
         }
         if(op2==1){
            cout<<"0\n";
            return;;
         }
         op2=1;
         hb=0;
      }
      if(s[i]==']'){
         if(op2==0){
            cout<<"0\n";
            return;;
         }
         if(hb==0){
            cout<<"0\n";
            return;;
         }
         op2=0;
      }
   }
   cout<<"1\n";
}
int main(){
   for(int i=1;i<=4;i++){
      solve();
   }
}
