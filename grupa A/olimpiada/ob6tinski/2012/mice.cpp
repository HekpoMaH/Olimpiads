#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
map<pair<int,int>, int> m,m2;
int n;
int mx;
void chek(int px,int py){
   if(m2[mp(px,py)]!=0)return;
   int s=m2[mp(px-1,py)];
   s+=m2[mp(px+1,py)];
   s+=m2[mp(px,py+1)];
   s+=m2[mp(px,py-1)];
   mx=max(s,mx);
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      int a,b,c;
      cin>>a>>b>>c;
      m[mp(a,b)]+=c;
   }
   m2=m;
   for(map<pair<int,int>, int>::iterator it=m.begin();it!=m.end();it++){
      int x=(it->first).first,y=(it->first).second;
      chek(x-1,y);
      chek(x+1,y);
      chek(x,y+1);
      chek(x,y-1);
   }
   cout<<mx<<"\n";
}
