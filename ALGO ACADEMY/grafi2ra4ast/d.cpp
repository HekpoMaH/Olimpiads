#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<lli,lli> pii;
const long long inf=1e15;
const int nmax=509;
#define mp make_pair
#define pb push_back
struct edge{
   lli node;
   lli travellingtime;
   lli departuretime;
   lli period;
   edge(){}
   edge(int _node,int _departuretime,int _period,int _travellingtime){
      node=_node;
      departuretime=_departuretime;
      period=_period;
      travellingtime=_travellingtime;
   }
};
vector<edge> a[nmax];
lli n,m,h,g,u,v,mej1,mej2;
lli mn=inf;
lli d[nmax],pred[nmax];
lli mtim;
bool used[nmax];
lli na4,kr;
priority_queue<pii, vector<pii>, greater<pii> >pq;
lli waittime(lli currenttime,edge fly){
   lli deptime=fly.departuretime;
   if(currenttime<=deptime){
      return deptime-currenttime;
   }
   else{
      currenttime%=fly.period;
      deptime%=fly.period;
      if(currenttime<=deptime){
         return deptime-currenttime;
      }
      else{
         return deptime+fly.period-currenttime;
      }
   }
   return -3;
}
bool chek(lli s){
   for(int i=1;i<=n;i++){
      d[i]=inf;
   }
   d[1]=0;
   pred[1]=-1;
   pii current;
   pq.push(mp(0,1));
   lli node,len,node2,len2;
   while(pq.size()){
      current=pq.top();
      pq.pop();
      len=current.first;
      node=current.second;
      if(d[node]<len)continue;
      d[node]=len;
      //cout<<d[node]<<"\n";
      for(int i=0;i<a[node].size();i++){
         //cout<<len<<" "<<len2<<"\n";
         len2=len;
         len2+= node==1 ? 1 : s;
         len2+= waittime(len2,a[node][i])+a[node][i].travellingtime;
         node2=a[node][i].node;
         if(d[node2]>len2){
            d[node2]=len2;
            pred[node2]=node;
            pq.push(mp(len2,node2));
         }
      }
   }
   return d[n]<=mtim;
}
void read(){
   int aa,b,f,t,p;
   scanf("%d %d",&aa,&b);
   n=aa;
   m=b;
   for(int i=1;i<=m;i++){
      scanf("%d,%d,%d,%d,%d",&aa,&b,&f,&t,&p);
      a[aa].pb(edge(b,f,p,t));
   }
   cin>>mtim;
}
void solve(){
   lli l=0,r=1e12;
   int mid;
   while(l+1<r){
      mid=(l+r)/2;
      if(chek(mid)){
         l=mid;
      }
      else{
         r=mid;
      }
   }
   cout<<l<<"\n";
}
int main(){
   read();
   solve();
}
