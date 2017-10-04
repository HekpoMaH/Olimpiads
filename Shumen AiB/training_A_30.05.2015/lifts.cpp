#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long lli;
typedef pair<lli,lli> pii;
const int nmax=1e6+9;
lli d[nmax];
vector<pii> a[nmax];
lli N,U,D,I,J,L;
set<int> s;
priority_queue<pii,vector<pii>,greater<pii> >pq;
int inf;
void dijkstra(){
   d[1]=0;
   memset(d,63,sizeof(d));
   inf=d[2];
   pii curr;
   pq.push(mp(0,1));
   lli node,len,node2,len2;
   while(!pq.empty()){
      curr=pq.top();
      node=curr.se;
      len=curr.fi;
      //cout<<node<<"\n";
      pq.pop();
      if(d[node]<len)continue;
      d[node]=len;
      for(int i=0;i<(int)a[node].size();i++){
         node2=a[node][i].fi;
         len2=len+a[node][i].se;
         //cout<<node2<<" "<<len2<<" "<<d[node2]<<"\n";
         if(len2<d[node2]){
            d[node2]=len2;
            pq.push(mp(len2,node2));
         }
      }
   }
   assert(d[N]!=inf);
   cout<<d[N]<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>N>>U>>D>>I>>J>>L;
   s.insert(1);
   s.insert(N);
   for(int i=1;i<=L;i++){
      int k;
      cin>>k;
      int etaji[1009];
      for(int j=1;j<=k;j++){
         cin>>etaji[j];
         s.insert(etaji[j]);
      }
      for(int j=1;j<=k;j++){
         for(int j1=j+1;j1<=k;j1++){
            lli v1=etaji[j];
            lli v2=etaji[j1];
            lli dis=I+J;
            a[v1].pb(mp(v2,dis));
            a[v2].pb(mp(v1,dis));
            //cout<<"added "<<v1<<" "<<v2<<" "<<dis<<"\n";
         }
      }
   }
   set<int>::iterator it;
   set<int>::iterator it2;
   //cout<<(s.find(7)!=s.end())<<"\n";
   for(it=s.begin();it!=s.end();it++){
      //if(*it==N)break;
      it2=it;
      it2++;
      for(it2;it2!=s.end();it2++){
         //cout<<"added "<<*it<<" "<<*it2<<" "<<(*it2-*it)*U<<"\n";
         a[*it].pb(mp(*it2,(*it2-*it)*U));
         a[*it2].pb(mp(*it,(*it2-*it)*D));
         //cout<<"added "<<*it2<<" "<<*it<<" "<<(*it2-*it)*D<<"\n";
      }
   }
   //assert(a[1].size()!=0);
   dijkstra();
}
