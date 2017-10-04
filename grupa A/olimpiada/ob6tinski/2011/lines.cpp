#include<bits/stdc++.h>
using namespace std;
#define pb push_back
struct line{
   int a,b,c;
   line(){}
   line(int _a,int _b,int _c){
      a=_a;
      b=_b;
      c=_c;
   }
};
vector<line> kls[1009];
int n;
int br=0;
bool sameclass(line x1,line x2){
   return x1.a*x2.b==x1.b*x2.a;
}
bool isnoteq(line x1,line x2){
   return (x1.a*x2.c!=x1.c*x2.a)||(x1.b*x2.c!=x2.b*x1.c);
}
void read(){
   cin>>n;
   line x;
   for(int i=1;i<=n;i++){
      cin>>x.a>>x.b>>x.c;
      int j;
      for(j=1;j<=br&&!sameclass(x,kls[j].back());j++);
      if(j<=br){
         int fl=1;
         for(int k=0;k<kls[j].size();k++){
            if(!isnoteq(x,kls[j][k]))fl=0;
         }
         if(fl==1)kls[j].pb(x);
      }
      if(j==br+1)kls[++br].pb(x);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   int sum=0;
   for(int i=1;i<=br;i++){
      sum+=kls[i].size();
   }
   cout<<sum<<"\n";
   cout<<br<<"\n";
}
