#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=1e5+9;
lli scl[nmax];
lli sop[nmax];
string s;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   srand(time(NULL));
   cin>>s;
   int n=s.size();
   lli balance=0,aflh=0,lp;
   for(int i=0;i<n;i++){
      if(i>0)scl[i]=scl[i-1],sop[i]=sop[i-1];
      if(s[i]=='(')sop[i]++,aflh++,balance++;
      if(s[i]==')')scl[i]++,balance--;
      if(s[i]=='#'){
         aflh=0;
         lp=i;
      }
      if(balance<0){
         cout<<-1<<"\n";
         exit(0);
      }
   }
   vector<lli> ans;
   balance=0;
   for(int i=0;i<n;i++){
      if(s[i]=='(')balance++;
      if(s[i]==')')balance--;
      //cout<<i<<" b="<<balance<<"\n";
      if(s[i]=='#'){
         lli ss=balance;
         lli otvorenisled=sop[n-1];
         if(i>0)otvorenisled-=sop[i-1];
         lli zatvorenisled=scl[n-1];
         if(i>0)zatvorenisled-=scl[i-1];
         ss=balance-(zatvorenisled-aflh);
         //cout<<otvorenisled<<" "<<zatvorenisled<<"\n";
         if(i!=lp){
            ans.push_back(1);
            balance--;
         }
         else{
            ans.push_back(balance-(zatvorenisled-otvorenisled));
            if(ans[ans.size()-1]<=0){
               cout<<-1<<"\n";
               exit(0);
            }
            balance-=ans[ans.size()-1];
         }
      }
      if(balance<0){
         cout<<-1<<"\n";
         exit(0);
      }
   }
   if(balance!=0){
      cout<<-1<<"\n";
      exit(0);
   }
   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<"\n";
   }
}
