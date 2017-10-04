#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int n,m;
typedef pair<long long,pair<int,int> > wtf;
struct el{
};
priority_queue<pair<long long,pair<int,int> > > pq;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int k,mm,nn;
   cin>>n>>m>>k;
   nn=n;mm=m;
   int br=1;
   pq.push(make_pair(1*1,make_pair(1,1)));
   while(br<k){
      pair<long long,pair<int,int> > cur=pq.top();
      pq.pop();
      br++;
      m=cur.second.first;n=cur.second.second;
      cout<<cur.first<<" "<<m<<" "<<n<<endl;
      if(m+1<=mm)pq.push(make_pair((m+1)*n,make_pair(m+1,n)));
      if(n+1<=nn)pq.push(make_pair(m*(n+1),make_pair(m,n+1)));
   }
   cout<<pq.top().first<<"\n";
}
