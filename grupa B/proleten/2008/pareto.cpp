#include<bits/stdc++.h>
using namespace std;
const int nmax=500009;
struct vec{
   int x,y;
   vec(){}
   vec(int _x,int _y){
      x=_x;
      y=_y;
   }
};
int n;
vec p[nmax];
int used[nmax];
bool cmp(vec f,vec s){
   if(f.x>s.x)return true;
   if(f.x<s.x)return false;
   if(f.y>s.y)return true;
   return false;
}
int findopt(){
   int mxy=-1e9;
   int br=0;
   p[0].x=-1;
   for(int i=1;i<=n;i++){
      if(p[i].x!=p[i-1].x&&p[i].y>mxy){
         br++;
         used[i]=1;
         mxy=p[i].y;
      }
   }
   return br;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      p[i]=vec(x,y);
   }
   sort(p+1,p+n+1,cmp);
   int k=findopt();
   //for(int i=1;i<=n;i++)cout<<p[i].x<<" "<<p[i].y<<" "<<used[i]<<"\n";
   cout<<k<<" ";
   int br=0;
   for(int i=1;i<=n;i++){
      if(used[i]==1){
         br++;
         p[i].x=-1e8;
         p[i].y=-1e8;
      }
   }
   //cout<<"n="<<n<<" ";
   sort(p+1,p+n+1,cmp);
   n-=k;
   //cout<<"after="<<n<<"\n";
   //for(int i=1;i<=n+k;i++)cout<<p[i].x<<" "<<p[i].y<<"\n";
   //cout.flush();
   cout<<findopt()<<"\n";
}
