#include<bits/stdc++.h>
using namespace std;
struct state{
   int sumr[6],sumc[6],sumd[3];
   int tab[6][6];
};
int tab[6][6],perm[6];
set<unsigned> vis;
vector<state> ans;
long long he6i(state x,int s){
   unsigned hash=0;
   for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
         hash=(unsigned)((unsigned)hash*8+(unsigned)x.tab[i][j]);
      }
   }
   hash=(unsigned)((unsigned)hash*8+(unsigned)s);
   return hash;
}
void go(state x){
   int fl=1;
   //cout<<"EEEEEEEE"<<endl;
   if(vis.find(he6i(x,0))!=vis.end())return;
   vis.insert(he6i(x,0));///to be continued here
   cout<<"he6="<<he6i(x,0)<<" "<<vis.size()<<" "<<ans.size()<<"\n";
   cout.flush();
   for(int i=1;i<=4;i++)cout<<x.sumr[i]<<" ";cout<<"\n";
   for(int i=1;i<=4;i++)cout<<x.sumc[i]<<" ";cout<<"\n";
   for(int i=1;i<=2;i++)cout<<x.sumd[i]<<" ";cout<<"\n";
   assert(x.sumr[1]>=0);
   set<int> sums;
   for(int i=1;i<=4;i++){
      sums.insert(x.sumr[i]);
      sums.insert(x.sumc[i]);
   }
   for(int i=1;i<=2;i++)sums.insert(x.sumd[i]);
   if(sums.size()==8)ans.push_back(x);
   state nx;
   for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
         for(int k=1;x.sumr[i]+k<=7&&x.sumc[j]+k<=7;k++){
            nx=x;
            nx.tab[i][j]=x.tab[i][j]+k;
            nx.sumr[i]=x.sumr[i]+k;
            nx.sumc[i]=x.sumc[i]+k;
            nx.sumd[1]=x.sumd[1];
            if(i==j)nx.sumd[1]+=k;
            nx.sumd[2]=x.sumd[2];
            if(i==5-j)nx.sumd[2]+=k;
            go(nx);
         }
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   for(int i=1;i<=4;i++)perm[i]=i;
   state starter; //);
   for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
         starter.tab[i][j]=0;
      }
      starter.sumr[i]=starter.sumc[i]=0;
      starter.sumd[i%2+1]=0;
   }
   //vis.insert(he6i(starter));
   go(starter);
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++){
      for(int i1=1;i1<=4;i1++){
         for(int j1=1;j1<=4;j1++){
            cout<<ans[i].tab[i1][j1]<<" ";
         }
      }
      cout<<endl;
   }
}

