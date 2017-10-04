#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli zor(lli start,lli len){
   lli m,t;
   if(start%2){
      t=start+len-(len&3);
      if(t>=start+len)t-=4;
      m=start;
   }
   else{
      t=start+len-1-(len&3);
      m=0;
   }
   for(lli i=t+1;i<start+len;i++)m^=i;
   return m;
}
lli mx(lli cnt,lli lo,lli hi,lli &from){
   if(cnt&1){
      lli m1=zor(hi-cnt,cnt),m2=zor(hi-cnt+1,cnt);
      if(m1>m2){
         from=hi-cnt;
         return m1;
      }
      from=hi-cnt+1;
      return m2;
   }
   lli r=lo^hi;
   lli m=1,mask;
   lli mxx,last,a;
   while(m<=r)m*=2;
   mask=(~(m-1))&hi;
   m/=2;
   m|=mask;
   last=(cnt&3)?0:1;
   lo=max(lo,m-cnt+1);
   hi=min(hi,m+cnt-1);
   if(hi%2)hi--;
   if(!lo%2)lo++;
   mxx=lo^(lo+cnt-1)^last;
   from=lo;
   for(lli f=lo+2;f<=hi-cnt+1;f+=2){
      a=f^(f+cnt-1)^last;
      if(a>mxx){
         mxx=a;
         from=f;
      }
   }
   return mxx;
}
int main(){
   lli a,b,n,f;
   cin>>a>>b>>n;
   cout<<mx(n,a,b,f)<<"\n";
}
