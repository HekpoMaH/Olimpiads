#include<iostream>
#include<algorithm>
using namespace std;
const long long nmax=200001;
#define pb push_back
struct stena{
   long long x,y1,y2;
   stena(){}
   stena(long long _x,long long _y1,long long _y2){
      x=_x;
      y1=_y1;
      y2=_y2;
   }
};
stena a[nmax];
const long long inf=1e10;
vector<stena> wtf[nmax];
long long n;
inline bool cmp(stena ed,stena dv){
   if(ed.x<dv.x)return true;
   if(ed.x>dv.x)return false;
   if(ed.y1<dv.y1)return true;
   if(ed.y1>dv.y1)return false;
   if(ed.y2<dv.y2)return true;
   return false;
}
inline bool chek(stena ed,stena dv){
   if(ed.y1>dv.y1&&ed.y1<dv.y2)return true;
   if(ed.y2>dv.y1&&ed.y2<dv.y2)return true;
   if(dv.y1>ed.y1&&dv.y1<ed.y2)return true;
   if(dv.y2>ed.y1&&dv.y2<ed.y2)return true;
   //if(ed.x!=dv.x&&ed.y1==dv.y1&&ed.y2==dv.y2)return true;
   return false;
}
long long mn=inf;
bool fl2=0;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   a[0].x=-3*inf;
   for(long long i=1;i<=n;i++){
      cin>>a[i].x>>a[i].y1>>a[i].y2;
      //if(a[i].y1>a[i].y2)swap(a[i].y1,a[i].y2);
   }
   long long br=0;
   sort(a+1,a+n+1,cmp);
   for(long long i=1;i<=n;i++){
      if(a[i].x!=a[i-1].x){
         br++;
      }
      wtf[br].pb(a[i]);
   }
   bool fl=0;
   for(int i=1;i<br;i++){
      fl=0;
      for(int j=0;j<(int)wtf[i].size();j++){
         if(wtf[i+1].size()==0)break;
         if(wtf[i+1][0].x-wtf[i][0].x>=mn)break;
         for(int k=0;k<(int)wtf[i+1].size();k++){
            if(chek(wtf[i][j],wtf[i+1][k])){
               fl=1;
               fl2=1;
               mn=min(mn,wtf[i+1][k].x-wtf[i][j].x);
               break;
            }
         }
         if(fl==1)break;
      }
   }
   if(fl2)cout<<mn<<"\n";
   else cout<<"--\n";
}
