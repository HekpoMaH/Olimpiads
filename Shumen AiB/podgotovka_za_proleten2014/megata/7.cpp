#include<iostream>
#include<string>
using namespace std;
bool les(string x,string y){
   if(x.size()<y.size())return true;
   if(x.size()>y.size())return false;
   for(int i=0;i<x.size();i++){
      if(x[i]<y[i])return true;
      if(x[i]>y[i])return false;
   }
   return false;
}
void solve(){
   string s;
   cin>>s;
   string pal=s.substr(0,s.size()/2);
   if(s.size()%2==1){
      pal=pal+s[s.size()/2]+pal;
   }
   else pal=pal+pal;
   if(les(pal,s)){
      if(pal[pal.size()/2]-'0'<9){
         pal[pal.size()/2]++;
      }
      else{
         pal="";
         for(int i=1;i<=s.size()+1;i++)pal+="1";
      }
   }
   cout<<pal<<"\n";
}
int main(){
   int t;
   cin>>t;
   while(t--)solve();
}
