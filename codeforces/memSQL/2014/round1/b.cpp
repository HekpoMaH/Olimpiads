#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<lli,lli> pii;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n,m;
bool inner(pii x){
   if(x.first<0)return false;
   if(x.first>n)return false;
   if(x.second<0)return false;
   if(x.second>m)return false;
   return true;
}
set<pii> s;
void add(int x,int y){
   if(inner(mp(x,y))==true)s.insert(mp(x,y));
}
typedef set<pii>::iterator sit;
lli dis(pii x, pii y) {
	return ((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
}
int main(){
   cin>>n>>m;
   add(0,0);
   add(0,1);
   add(1,0);
   add(1,1);
   add(n,m);
   add(n-1,m);
   add(n-1,m-1);
   add(n,m-1);
   add(0,m);
   add(1,m);
   add(0,m-1);
   add(1,m-1);
   add(n,0);
   add(n,1);
   add(n-1,0);
   add(n-1,1);
   lli mx=-1;
   pii p[6];
   for(sit i=s.begin();i!=s.end();i++){
      for(sit j=s.begin();j!=s.end();j++){
         for(sit k=s.begin();k!=s.end();k++){
            for(sit l=s.begin();l!=s.end();l++){
               if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
               lli dist=dis(*i,*j)+dis(*j,*k)+dis(*k,*l);
               if(mx<dist){
                  mx=dist;
                  p[0]=*i;
                  p[1]=*j;
                  p[2]=*k;
                  p[3]=*l;
               }
            }
         }
      }
   }
   for(int i=0;i<4;i++){
      cout<<p[i].fi<<" "<<p[i].se<<"\n";
   }
}
