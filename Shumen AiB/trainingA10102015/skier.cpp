#include<bits/stdc++.h>
using namespace std;
const int nmax=2*(1e4+9);
const double inf=1e9;
const int offset=1e4+1;
typedef pair<int,int> pii;
#define mp make_pair
struct vec {
   double x, y; 
   double shtraf;
   double t;
   int type;


   vec() {}
   vec(double _x, double _y,int _type,double _shtraf) { x = _x; y = _y; type=_type; shtraf=_shtraf;}

   vec operator+(vec b) { return vec(x+b.x, y+b.y,type,shtraf); }
   vec operator-(vec b) { return vec(x-b.x, y-b.y,type,shtraf); }

   
   double len2() { return x*x + y*y; }
   double len() { return sqrt( this->len2() ); }
};
double cross(vec u, vec v) {
  return u.x*v.y - v.x*u.y;
}
int n;
vec S,F,Fiki;
vec P[nmax];
double T[nmax];
double indexno[nmax];
map<pair<int,int> ,int> idxs;
int pSz;
bool cmpR(vec fi,vec se){
   if(fi.y>se.y)return true;
   if(fi.y<se.y)return false;
   if(fi.x<se.x)return true;
   return false;

}
bool cmpPol(vec B,vec C){
   vec AB=B-Fiki;
   vec AC=C-Fiki;
   if(cross(AB,AC)<0.0){
      return true;
   }
   if(cross(AB,AC)>0.0){
      return false;
   }
   if(B.type!=C.type)return B.type>C.type;
   if(C.type==3)return AB.len2()<AC.len2();
   return AB.len2()<AC.len2();
}
void input(){
   cin>>n;
   cin>>S.x>>S.y;
   S.type=2;
   cin>>F.x>>F.y;
   F.type=2;
   S.x+=offset;S.y+=offset;
   F.x+=offset;F.y+=offset;
   int br=1;
   for(int i=1;i<=n;i++){
      double aa,bb,yy,cc;
      cin>>aa>>bb>>yy>>cc;
      P[++br]=vec(aa+offset,yy+offset,3,cc);
      P[++br]=vec(bb+offset,yy+offset,1,cc);
   }
   P[1]=S;
   P[2*n+2]=F;
   n*=2;
   n+=2;
}

void add(int idx,double val){
   while(idx<=nmax){
      indexno[idx]+=val;
      idx+=idx&(-idx);
   }
}
double get(int from,int to){
   double su1=0.0,su2=0.0;
   from--;
   while(from>0){
      su1+=indexno[from];
      from-=from&(-from);
   }
   from=to;
   while(from>0){
      su2+=indexno[from];
      from-=from&(-from);
   }
   return su2-su1;
}
void solve(){
   sort(P+1,P+2*n+1,cmpR);
   double sum=0.0;
   for(int i=1;i<=n;i++){
      sum+=P[i].shtraf;
   }
   //cout<<T[1]<<"\n";
   for(int j=1;j<=n;j++){
      P[j]=P[j];
   }
   P[1].t=sum/2.0;
   for(int i=2;i<=n;i++){
      P[i].t=inf;
      //memset(indexno,0,sizeof(indexno));
      Fiki=P[i];
      sort(P+1,P+i,cmpPol);
      
      //for(int j=1;j<i;j++){
      //   cerr<<P[j].x-1<<" x "<<P[j].y<<"\n";
      //}
      //cerr<<"==================================\n";
      for(int j=1;j<i;j++){
         if(P[i].y==P[j].y)continue;
         double tim=P[j].t;
         vec ots=P[j]-P[i];
         //cerr<<tim<<"\n";
         tim+=ots.len();
         //cerr<<tim<<"\n";
         if(P[j].y-P[i].y>1.0)tim-=get(1,P[j].y-1);
         //cerr<<get(1,P[j].y-1)<<" "<<tim<<"\n";
         P[i].t=min(P[i].t,tim);
         if(P[j].type==1)add(P[j].y,-P[j].shtraf);
         if(P[j].type==3)add(P[j].y,P[j].shtraf);
      }
      P[i].t=P[i].t-P[i].shtraf;
      //cerr<<P[i].x-1<<" "<<P[i].y<<" "<<i<<" "<<P[i].t<<"\n";
      //cerr<<"==================================\n";
   }
   cout<<setiosflags(ios::fixed)<<setprecision(4)<<P[n].t<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   input();
   solve();
}
