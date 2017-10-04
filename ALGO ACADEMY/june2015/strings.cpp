#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const int base=47;
unordered_map<unsigned,int> cnt;
string s;
int k;
int n;
unsigned pw[nmax];
unsigned hash_s[nmax];
void prep(){
   hash_s[0]=s[0]-'a';
   pw[0]=1;
   for(int i=1;i<n;i++){
      hash_s[i]=hash_s[i-1]*base+s[i]-'a';
      pw[i]=pw[i-1]*base;
   }
}
unsigned geth(int pos1,int pos2){
   //a1*base^n-1+a2*base^n-2+..+an
   
   return hash_s[pos2]-hash_s[pos1-1]*pw[pos2-pos1+1];
}
//3*47^2+4*47+1
bool eval(int len){
   cnt.clear();
   for(int i=0;i<n-len+1;i++){
      cnt[geth(i,i+len-1)]++;
      if(cnt[geth(i,i+len-1)]>=k)return true;
   }
   return false;
}

string getans(int len){
   cnt.clear();
   for(int i=0;i<n-len+1;i++){
      cnt[geth(i,i+len-1)]++;
   }
   int mx=0;
   string ansm;
   for(int i=0;i<n-len+1;i++){
      if(cnt[geth(i,i+len-1)]>mx){
         mx=cnt[geth(i,i+len-1)];
         ansm=s.substr(i,len);
      }
   }
   return ansm;
}
int main(){
   cin>>s;
   cin>>k;
   n=s.size();
   prep();
   int l=0,r=n+1,mid;
   while(l+1<r){
      mid=(l+r)/2;
      if(eval(mid)){
         l=mid;
      }
      else{
         r=mid;
      }
   }
   if(l==0)cout<<-1<<"\n";
   else cout<<getans(l)<<"\n";
}
