#include<bits/stdc++.h>
using namespace std;
const int nmax=2e6+9;
const int inf=1e9;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long lli;
int mh,mv;
int n,q;
int xh[nmax],yh[nmax];
int xv[nmax],yv[nmax];
int m;
int x[nmax],y[nmax];
int x1[nmax],y11[nmax],x2[nmax],y2[nmax];
pii pt[2*nmax];
int atot[nmax];
int ans[nmax];
int bit[nmax];
pii sobs[2*nmax];
vector <int> ad[nmax];
void add(int t){
   while(t<nmax){
      bit[t]++;
      t+=t&(-t);
   }
}
int get(int t){
   int re=0;
   while(t!=0){
      re+=bit[t];
      t-=t&(-t);
   }
   return re;
}
void solve(){
   for(int i=1;i<nmax;i++)bit[i]=0,ad[i].clear();
   for(int i=1;i<=m;i++){
      ad[x[i]].pb(y[i]);
   }
   for(int i=1;i<=q;i++){
      ans[i]=0;
      sobs[i*2-1]=mp(x1[i]-1,i);
      sobs[i*2]=mp(x2[i],-(i));
   }
   sort(sobs+1,sobs+2*q+1);
   //for(int i=1;i<=2*q;i++)cout<<sobs[i].fi<<" "<<sobs[i].se<<"\n";
   int pp=1;
   //cout<<"DONE"<<endl;
   sobs[2*q+1].fi=nmax;
   for(int i=0;i<nmax;i++){
      //cout<<i<<endl;
      for(int j=0;j<(int)ad[i].size();j++){
         add(ad[i][j]);
      }
      //cout<<sobs[pp].fi<<" "<<sobs[pp].se<<endl;
      while(sobs[pp].first==i){
   //cout<<"DONE"<<endl;
         if(sobs[pp].second<0){
            int v=-sobs[pp].se;
            ans[v]+=(get(y2[v])-get(y11[v]-1));
         }
         else{
            int v=sobs[pp].se;
            ans[v]-=(get(y2[v])-get(y11[v]-1));
         }
         pp++;
         //cout<<pp<<endl;
      }
   }

}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>q;
   cin>>n>>q;
   n--;
   for(int i=1;i<=n;i++){
      string tp;//char ne6to precakva
      int xc,yc;
      cin>>tp>>xc>>yc;
      pt[i*2-1]=mp(xc,yc);
      if(tp[0]=='h'){
         xh[++mh]=xc;
         yh[mh]=yc;
         pt[i*2]=mp(xc+1,yc);
         //cout<<"pt["<<i*2<<"]="<<pt[i*2]<<"\n";
      }
      else{
         xv[++mv]=xc;
         yv[mv]=yc;
         pt[i*2]=mp(xc,yc+1);
         //cout<<"pt["<<i*2<<"]="<<pt[i*2]<<"\n";
      }
   }
   for(int i=1;i<=q;i++){
      cin>>x1[i]>>y11[i]>>x2[i]>>y2[i];
   }
   m=0;
   sort(pt+1,pt+2*n+1);
   //for(int i=1;i<=2*n;i++)cout<<pt[i].fi<<" "<<pt[i].se<<"\n";
   for(int i=1;i<=2*n;i++){
      if((i==0)||(pt[i]!=pt[i-1])){
         x[++m]=pt[i].fi;
         y[m]=pt[i].se;
      }
   }
   solve();
   for(int i=1;i<=q;i++){
      atot[i]=ans[i];
   }
   m=mh;
   for(int i=1;i<=m;i++)x[i]=xh[i],y[i]=yh[i];
   for(int i=1;i<=q;i++)x2[i]--;
   solve();
   for(int i=1;i<=q;i++){
      x2[i]++;
      atot[i]-=ans[i];
   }
   m=mv;
   for(int i=1;i<=m;i++)x[i]=xv[i],y[i]=yv[i];
   for(int i=1;i<=q;i++)y2[i]--;
   solve();
   for(int i=1;i<=q;i++){
      y2[i]++;
      atot[i]-=ans[i];
   }
   for(int i=1;i<=q;i++){
      cout<<atot[i]<<"\n";
   }
}
