#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef long long lli;
typedef pair<int,int> pii;
set<pii> gd;
typedef set<pii> ::iterator siter;
const int nmax=300009;
lli sm[4*nmax];
int val[4*nmax];
int mx[4*nmax];
int lv,rv,nv;
int n,q;
lli ans=0;
string s;
void set_val(int v,int vl,int sz){
   val[v]=vl;
   ans-=sm[v];
   sm[v]=(lli)(vl*sz);
   ans+=sm[v];
   mx[v]=vl;
}
void set_val2(int v,int vl,int sz){
   val[v]=vl;
   sm[v]=(lli)(vl*sz);
   mx[v]=vl;
}
void push(int v,int sz){
   if(val[v]==-1)return;
   set_val2(v*2+1,val[v],(sz+1)/2);
   set_val2(v*2+2,val[v],sz/2);
   val[v]=-1;
}
void modify_rmq(int v,int l,int r){
   if(l>rv)return;
   if(lv>r)return;
   int sz=(r-l+1);
   if(lv<=l&&r<=rv&&mx[v]<=nv){
      set_val(v,nv,sz);
      return;
   }
   if(l==r)return;
   push(v,sz);
   if(mx[v*2+1]<nv)modify_rmq(v*2+2,(l+r)/2+1,r);
   modify_rmq(v*2+1,l,(l+r)/2);
   mx[v]=mx[v*2+2];
   sm[v]=sm[v*2+1]+sm[v*2+2];
}
void ad(int lg,int rg){
   siter it=gd.lower_bound(mp(lg,0));
   it--;
   if(it->se+1<lg)it++;
   else lg=it->fi;
   siter sit=it;
   while(it->fi<=rg+1){
      if(it->se>rg)rg=it->se;
      it++;
   }
   gd.erase(sit,it);
   gd.insert(mp(lg,rg));
   lv=lg;
   rv=rg;
   nv=rg+1;
   modify_rmq(0,0,n-1);
}
void er(int lg,int rg){
   int l1=-1,r1=-1,l2=-1,r2=-1;
   siter it=gd.lower_bound(mp(lg,0));
   it--;
   if(it->se>=lg){
      l1=it->fi;
      r1=lg-1;
   }
   else it++;
   siter sit=it;
   while(it->se==rg){
      it++;
   }
   if(it->fi<=rg){
      l2=rg+1,r2=it->se;
      it++;
   }
   gd.erase(sit,it);
   if(l1!=-1)gd.insert(mp(l1,r1));
   if(l2!=-1)gd.insert(mp(l2,r2));
}
int main(){
   ios_base::sync_with_stdio(false);
   
   cin.tie(0);
   cin>>n>>q;
   ans=-((lli)n*(lli)(n-1))/2LL;
   gd.insert(mp(-2,-2));
   gd.insert(mp(n+1,n+1));
   for(int i=0;i<n;i++){
      lv=rv=nv=i;
      modify_rmq(0,0,n-1);
   }
   cin>>s;
   //ad(n,n);
   //cout<<"EPIc"<<endl;
   for(int i=0;i<n;i++){
      if(s[i]=='1')ad(i,i);
   }
   cout<<ans<<"\n";
   for(int i=0;i<q;i++){
      int l,r,c;
      cin>>l>>r>>c;
      l--;r--;
      if(c==0)er(l,r);
      else ad(l,r);
      cout<<ans<<"\n";
   }
}

