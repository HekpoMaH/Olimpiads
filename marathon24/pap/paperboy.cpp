#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int n,m;
const int maxp=400*400+9;
const int maxn=409;

clock_t glok=clock();
pair<int,int> givepos(int x){
   return mp(x/m+min(1,x%m),x%m==0 ? m : x%m);
}
int szp;
double TL=1600.00;
bool intime(){
   return ((double)(clock()-glok)/(double)CLOCKS_PER_SEC)<TL;
}
int path[maxp],bestp[maxp],bestans=1e9;
int cbestans=1e9;
int cbestp[maxp];
int reres(int p[]){
   int used[maxp];
   memset(used,0,sizeof(used));
   int mx=0;
   for(int i=1;i<n*m;i++){
      int len;
      pair<int,int> p1,p2;
      p1=givepos(p[i]);
      p2=givepos(p[i+1]);
      len=abs(p1.first-p2.first)+abs(p2.second-p1.second);
      used[len]++;
      mx=max(used[len],mx);
   }
   return mx;
}
void update(int p[],int nres){
   for(int i=1;i<=szp;i++){
      bestp[i]=p[i];
   }
   bestans=nres;
}
void update2(int p[],int nres){
   for(int i=1;i<=szp;i++){
      cbestp[i]=p[i];
   }
   cbestans=nres;
}
void coolstuff(){
   path[1]=((long long)rand()*rand())%szp+1;
   int used[maxp];
   memset(used,0,sizeof(used));
   set<int> free;
   for(int i=1;i<=szp;i++)free.insert(i);
   for(int i=2;i<=szp;i++){
      set<int>::iterator it;
      int mn=1e9,mnpos;
      pair<int,int> p1,p2;
      int len;
      for(it=free.begin();it!=free.end();it++){
         p1=givepos(path[i-1]);
         p2=givepos(*it);
         len=abs(p1.first-p2.first)+abs(p2.second-p1.second);
         if(used[len]<mn){
            mn=used[len];
            mnpos=*it;
         }
      }
      path[i]=mnpos;
      free.erase(mnpos);
      p1=givepos(path[i-1]);
      p2=givepos(path[i]);
      len=abs(p1.first-p2.first)+abs(p2.second-p1.second);
      used[len]++;
   }
   int dares=reres(path);
   update(path,dares);
}
void messup(){
   int dares=reres(path);
   cbestans=1e9;
   if(dares<bestans){
      update(path,dares);
   }
   if(dares<cbestans){
      update2(path,dares);
   }
   int npath[maxp];
   for(int i=1;i<=10;i++){
      for(int j=1;j<=szp;j++)npath[j]=bestp[j];
      int fpos=((long long)rand()*rand())%(szp-1)+1;
      int len=rand()%min(szp-fpos,5)+1;
      //while(fpos+len>szp)len=rand()%10+1;
      reverse(npath+fpos,npath+fpos+len+1);
      dares=reres(npath);
      //if(dares<cbestans){
      //   update2(npath,dares);
      //}
      if(dares<bestans){
         update(npath,dares);
      }
   }
}
void out(){
   int anso[maxn][maxn];
   for(int i=1;i<=szp;i++){
      pair<int,int> pa=givepos(bestp[i]);
      anso[pa.first][pa.second]=i;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(j<m)cout<<anso[i][j]<<" ";
         else cout<<anso[i][j];
      }
      cout<<"\n";
   }
}
int main(){
   srand(time(0));
   cin>>n>>m;
   szp=n*m;
   for(int i=1;i<=n*m;i++){
      path[i]=i;
   }
   while(intime()){
      random_shuffle(path+1,path+szp+1);
      messup();
   }
   out();
}
