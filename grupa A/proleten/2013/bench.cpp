#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long lli;
typedef pair<lli,lli> pii;
lli n,I,P;
set<lli> used;
map<pii,lli> dp;
vector<lli> vec;
void getPM(lli len){
   if(len==0)return;
   if(used.find(len)!=used.end())return;
   used.insert(len);
   getPM((len-1)/2);
   getPM(len/2);
}
lli makeDP(lli k,lli l){
   if(k<l)return dp[mp(k,l)]=0;
   if(k==l){
      return dp[mp(k,l)]=1;
   }
   if(dp.find(mp(k,l))==dp.end()){
      dp[mp(k,l)]=makeDP((k-1)/2,l)+makeDP(k/2,l);
   }
   return dp[mp(k,l)];
}
lli getBeg(lli k,lli l,lli p){
   lli ans=1;
   while(k!=l){
      if(dp[mp((k-1)/2,l)]<p){
         p-=dp[mp((k-1)/2,l)];
         ans+=(k-1)/2+1;
         k-=((k-1)/2+1);
      }
      else k-=(k/2+1);
   }
   return ans;
}
lli first(lli num){
   lli curr,lef,righ;
   getPM(n);
   //cout<<used.size()<<"\n";
   //cout.flush();
   set<lli>::reverse_iterator it;
   lli x=-1;
   lli num2=num;
   for(it=used.rbegin();it!=used.rend();it++){
      //cout<<"it="<<*it<<"\n";
      vec.pb(*it);
      curr=makeDP(n,*it);
      if(x==-1){
         if(num2>curr)num2-=curr;
         else x=*it;
      }
   }
   //assert(vec.size()!=0);
   //reverse(vec.begin(),vec.end());
   lef=getBeg(n,x,num2);
   righ=lef+x-1;
   //cout<<used.size()<<"\n";
   return (lef+righ)/2;
}
lli getLen(lli lef,lli righ,lli sz){
   lli mid=(lef+righ)/2;
   if(mid==P)return sz;
   if(P<mid)return getLen(lef,mid-1,(sz-1)/2);
   return getLen(mid+1,righ,sz/2);
}
lli getStart(lli lef,lli righ,lli sz,lli len){
   lli mid=(lef+righ)/2;
   if(mid==P){
      return 1;
   }
   if(mid>P)return getStart(lef,mid-1,(sz-1)/2,len);
   return dp[mp((sz-1)/2,len)]+getStart(mid+1,righ,sz/2,len);
}
lli second_part(lli num){
   //cout<<"bas "<<used.size()<<"\n";
   lli len,ans=0;
   //cout<<vec.size()<<"=vecsize \n";
   len=getLen(1,n,n);
   set<lli>::iterator it;
   lli i=0;
   while(vec[i]>len){
      ans+=dp[mp(n,vec[i])];
      i++;
   }
   ans+=getStart(1,n,n,len);
   return ans;
}
int main(){
   cin>>n>>I>>P;
   cout<<first(I)<<" ";
   cout<<second_part(P)<<"\n";
}
