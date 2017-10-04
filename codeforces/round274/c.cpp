#include<bits/stdc++.h>
using namespace std;
struct exam{
   int a,b;
   exam(){}
   exam(int _a,int _b){
      a=_a;
      b=_b;
   }
};
exam ex[5009];
int n;
bool cmp(exam fi,exam se){
   if(fi.a!=se.a)return fi.a<se.a;
   return fi.b<se.b;
}
vector<pair<int,int> >v;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      ex[i]=exam(x,y);
   }
   sort(ex+1,ex+n+1,cmp);
   int prevt=-100;
   for(int i=1;i<=n;i++){
      int q=min(ex[i].a,ex[i].b);
      if(q>=prevt){
         prevt=q;
         continue;
      }
      q=max(ex[i].a,ex[i].b);
      prevt=q;
   }
   cout<<prevt<<"\n";
}
