#include<bits/stdc++.h>
using namespace std;
const int nmax=59;
int dagr[nmax][nmax];
int n;
int m[nmax][nmax];
int b[nmax][nmax];
int d[nmax][nmax];
string s;
struct edge{
   int a,b;
   int post,czs,czr;
   edge(){}
   edge(int _a,int _b,int _post,int _czs,int _czr){
      a=_a;
      b=_b;
      post=_post;
      czs=_czs;
      czr=_czr;
   }
};
bool cmp(edge fi,edge se){
   if(fi.post>se.post)return true;
   if(fi.post<se.post)return false;
   if(fi.post==se.post&&se.post==0){
      return fi.czs<se.czs;
   }
   return fi.czr>se.czr;
}
vector<edge> e,t;
int parent[nmax],rank[nmax];
int find(int a){
   int a1=a;
   while(a!=parent[a])a=parent[a];
   while(a1!=parent[a1]){
      int to=parent[a1];
      parent[a1]=a;
      a1=to;
   }
   return a;
}
void uni(int a,int b){
   int ar=find(a);
   int br=find(b);
   if(rank[ar]<rank[br]){
      parent[ar]=br;
      return;
   }
   if(rank[br]<rank[ar]){
      parent[br]=ar;
      return;
   }
   parent[br]=ar;
   rank[ar]++;
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      parent[i]=i;
      cin>>s;
      for(int j=1;j<=n;j++){
         m[i][j]=s[j-1]-'0';
      }
   }
   for(int i=1;i<=n;i++){
      cin>>s;
      for(int j=1;j<=n;j++){
         if(s[j-1]>='A'&&s[j-1]<='Z')b[i][j]=s[j-1]-'A';
         else b[i][j]=s[j-1]-'a'+26;
      }
   }
   for(int i=1;i<=n;i++){
      cin>>s;
      for(int j=1;j<=n;j++){
         if(s[j-1]>='A'&&s[j-1]<='Z')d[i][j]=(s[j-1]-'A');
         else d[i][j]=(s[j-1]-'a'+26);
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         e.push_back(edge(i,j,m[i][j],b[i][j],d[i][j]));
      }
   }
   sort(e.begin(),e.end(),cmp);
   int cost=0;
   for(int i=0;i<e.size();i++){
      if(e[i].post==1){
         if(find(e[i].a)!=find(e[i].b)){
            t.push_back(e[i]);
            uni(e[i].a,e[i].b);
         }
         else{
            cost+=e[i].czr;
         }
      }
      if(e[i].post==0){
         if(find(e[i].a)!=find(e[i].b)){
            t.push_back(e[i]);
            uni(e[i].a,e[i].b);
            cost+=e[i].czs;
         }
      }
      //cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].post<<" "<<e[i].czs<<" "<<e[i].czs<<"\n";
   }
   cout<<cost<<"\n";
   
}
