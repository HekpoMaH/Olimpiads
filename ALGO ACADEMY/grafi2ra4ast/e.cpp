#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<lli,lli> pii;
const long long inf=1e15;
const int nmax=1e4;
#define mp make_pair
#define pb push_back
vector<pii> a[nmax];
lli n,m,h,g,u,v,mej1,mej2;
lli mn=inf;
lli d[nmax],pred[nmax];
bool used[nmax];
lli na4,kr;
lli negm=0;
priority_queue<pii, vector<pii>, greater<pii> >pq;
int br=0;
void chek(lli s){
   for(int i=1;i<=n;i++){
      d[i]=inf;
   }
   d[s]=0;
   pred[s]=-1;
   pii current;
   pq.push(mp(0,s));
   lli node,len,node2,len2;
   while(pq.size()){
      current=pq.top();
      pq.pop();
      len=current.first;
      node=current.second;
      if(d[node]<len)continue;
      d[node]=len;
      //cout<<d[node]<<"\n";
      if(d[node]<negm){
         cout<<"Negative cycle\n";
         exit(0);
      }
      for(int i=0;i<a[node].size();i++){
         //cout<<len<<" "<<len2<<"\n";
         len2=a[node][i].second;
         node2=a[node][i].first;
         if(d[node2]>len+len2){
            d[node2]=len+len2;
            pred[node2]=node;
            pq.push(mp(len+len2,node2));
         }
      }
   }
}
int firestarter;
void dfs(int x,int sm){
   used[x]=1;
   for(int i=0;i<a[x].size();i++){
      if(a[x][i].first==firestarter){
         if(sm+a[x][i].second<0){
            cout<<"Negative cycle\n";
            exit(0);
         }
      }
      if(used[a[x][i].first]==0){
         dfs(a[x][i].first,sm+a[x][i].second);
      }
   }
}
void read(){
   cin>>n;
   int x,y,z;
   string s="A";
   getline(cin,s);
   do{
      char sss[1009];
      getline(cin,s);
      for(int i=0;i<500;i++)sss[i]=' ';
      for(int i=0;i<s.size();i++){
         sss[i]=s[i];
      }
      int x,y,z;
      sscanf(sss,"%d %d %d",&x,&y,&z);
      //cout<<x<<" "<<y<<" "<<z<<"\n";
      a[x+1].pb(mp(y+1,z));
      
      if(z<0)negm+=z;
      //a[y+1].pb(mp(x+1,z));
   }while(!s.empty());
   if(n<2000)for(int i=1;i<=n;i++){
      memset(used,0,sizeof(used));
      firestarter=i;
      dfs(i,0);
   }
   chek(1);
   if(d[n]>=inf){
      cout<<"Could not reach last vertex\n";
      exit(0);
   }
   cout<<"Value: "<<d[n]<<"\n";
   stack<int> st;
   int k=n;
   while(pred[k]!=-1){
      st.push(k);
      k=pred[k];
   }
   cout<<"Path: "<<0<<" > ";
   while(!st.empty()){
      cout<<st.top()-1;
      if(st.size()>1)cout<<" > ";
      st.pop();
   }
   cout<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
}
