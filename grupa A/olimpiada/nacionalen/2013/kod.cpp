#include<bits/stdc++.h>
using namespace std;
const string digits="0123456789";
const int nmax=1<<12;
bool mi[nmax][nmax][2];
string s;
string minimp(int digits,int a,bool notz){
   if(mi[digits][a][notz])return string();
   for(int i=notz;i<10;i++){
      int c=find(s.begin()+a,s.end(),'0'+i)-s.begin();
      if(c==s.size())return (char)('0'+i)+string(digits-1,'0');
      if(digits==1)continue;
      string a=minimp(digits-1,c+1,false);
      if(!a.empty())return (char)('0'+i)+a;
   }
   mi[digits][a][notz]=1;
   return string();
}
string minimp(){
   for(int i=1;;i++){
      string a=minimp(i,0,true);
      if(!a.empty())return a;
   }
}
string generate(int a,int b){
   if(b<=a){
      string res;
      res=digits.substr(b,a-b+1);
      res+=digits.substr(0,b);
      res+=digits.substr(a+1,10-a-1);
      return res;
   }
   else{
      string res;
      res=digits[b];
      res+=digits[a];
      res+=digits.substr(0,b);
      res+=digits.substr(b+1,10-b-1);
      return res;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string b,res;
   cin>>s;
   b=minimp();
   cout<<b<<"\n";
   res+=digits.substr(1,b[0]-'1');
   for(int i=1;i<(int)b.size();i++){
      res+=generate(b[i-1]-'0',b[i]-'0');
   }
   while(res[0]=='0')res.erase(res.begin(),res.begin()+1);
   if(b=="1")res="0";
   cout<<res<<"\n";
}
