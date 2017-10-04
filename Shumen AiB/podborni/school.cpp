#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int nmax=3*1e5+9;
const int inf=1e9;
int n;
int a,b,c;
int m;
int mn1,mn2,mn3;
int mn=inf;
void check(int f,int s){
   int t=m-f-s;
   int score=abs(a-f)+abs(b-s)+abs(c-t);
   if(score<mn){
      mn=score;
      mn1=f;
      mn2=s;
      mn3=t;
   }
   //cout<<"cheking for "<<M94<<" "<<M95<<" "<<M96<<" "<<t94[M94]<<" "<<t95[M95]<<" "<<t96[M96]<<"\n";
}
void solve(){
   cin>>a>>b>>c;
   m=a+b+c;
   cin>>n;
   int t94[nmax],p94=0;
   int t95[nmax],p95=0;
   int t96[nmax],p96=0;
   mn=inf;
   for(int i=1;i<=n;i++){
      int year,score;
      cin>>year>>score;
      if(year==1994)t94[++p94]=score;
      if(year==1995)t95[++p95]=score;
      if(year==1996)t96[++p96]=score;
   }
   sort(t94+1,t94+p94+1);

   sort(t95+1,t95+p95+1);

   sort(t96+1,t96+p96+1);
   int m94=0,M95,m96=0;
   int M94,M96;
   int idx1=1,idx2=0;
   for(int i=1;i<=p95;i++){
      M95=i;
      while(idx1<=p94&&t94[idx1]<t95[M95])idx1++;
      while(idx2<p96&&t96[idx2+1]<t95[M95])idx2++;
      //cout<<"idx1="<<idx1<<" idx2="<<idx2<<"\n";
      if(idx1>p94)break;
      if(idx2==0)continue;
      M95=p95-i+1;
      m94=p94-idx1+1;
      m96=p96-idx2+1;
      int l=m-M95-p96;
      int r=m-M95-m96;
      //cout<<l<<" "<<r<<" "<<a<<" "<<p94<<" "<<m94<<" "<<m96<<"\n";
      M94=l;
      if(1<=M94&&M94<=m94&&l<=M94&&M94<=r)
      check(M94,M95);
      M94=r;
      if(1<=M94&&M94<=m94&&l<=M94&&M94<=r)
      check(M94,M95);
      M94=a;
      if(1<=M94&&M94<=m94&&l<=M94&&M94<=r)
      check(M94,M95);
      M94=1;
      if(1<=M94&&M94<=m94&&l<=M94&&M94<=r)
      check(M94,M95);
      M94=m94;
      if(1<=M94&&M94<=m94&&l<=M94&&M94<=r)
      check(M94,M95);
      //cout<<mn<<"\n";
      //cout<<"m's are "<<m94<<" "<<M95<<" "<<m96<<"\n";
   }
   if(mn==inf)cout<<-1<<"\n";
   else cout<<mn<<" "<<mn1<<" "<<mn2<<" "<<mn3<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
