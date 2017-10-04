#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int sg(int i,int j,int len){
   if(i>j)swap(i,j);
   if(i==0){
      if(j==0)return len%2;
      return len;
   }
   if(i==1){
      if(j==1)return min(len,1);
      return 0;
   }
   if(i==2){
      return min(len,1);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   cin>>s;
   int lef=0,righ,res=0,lefp=-1;
   for(int i=0;i<n;i++){
      if(s[i]!='0'){
         righ=s[i]-'0';
         int len=i-lefp-1;
         res^=sg(lef,righ,len);
         lefp=i;
         lef=righ;
         //cout<<lef<<" "<<righ<<" "<<len<<" "<<sg(lef,righ,len)<<"\n";
      }
      else if(i==n-1){
         righ=0;
         int len=n-lefp-1;
         res^=sg(lef,righ,len);
         //cout<<lef<<" "<<righ<<" "<<len<<" "<<sg(lef,righ,len)<<"\n";
      }
      //cout<<"at pos "<<i<<" res="<<res<<"\n";
   }
   if(res!=0)cout<<"FIRST\n";
   else cout<<"SECOND\n";
}
