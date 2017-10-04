#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define push_back(a,b) pb(a,b)
using namespace std;
const int nmax=1e5+9;
typedef long long lli;
string s;
int x[6];
int y[6];
bool issq(){
   for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
         if(x[i]==x[j]&&y[i]==y[j]&&i!=j)return false;
      }
   }
   int used[nmax];
   memset(used,0,sizeof(used));
   for(int i=1;i<=4;i++)used[x[i]+101]++;
   int br=0,fx,sx,fy,sy;
   for(int i=1;i<=nmax-1;i++){
      if(used[i]!=0){
         br++;
         if(br==1)fx=i;
         if(br==2)sx=i;
      }
   }
   if(br!=2)return false;
   memset(used,0,sizeof(used));
   for(int i=1;i<=4;i++)used[y[i]+101]++;
   br=0;
   for(int i=1;i<=nmax-1;i++){
      if(used[i]!=0){
         br++;
         if(br==1)fy=i;
         if(br==2)sy=i;
      }
   }
   if(sx-fx!=sy-fy)return false;
   if(br!=2)return false;
   return true;
}
int main(){
   for(int i=1;i<=2;i++){
      cin>>x[i]>>y[i];
   }
   if(x[1]==x[2]){
      x[3]=x[4]=x[1]+abs(y[1]-y[2]);
      y[3]=y[1];
      y[4]=y[2];
      if(x[3]>=-1000&&x[3]<=1000&&x[4]>=-1000&&x[4]<=1000){
         for(int i=3;i<=4;i++)cout<<x[i]<<" "<<y[i]<<" ";
         cout<<"\n";
         return 0;
      }
      x[3]=x[4]=x[1]-abs(y[1]-y[2]);
      y[3]=y[1];
      y[4]=y[2];
      for(int i=3;i<=4;i++)cout<<x[i]<<" "<<y[i]<<" ";
      cout<<"\n";
      return 0;
   }
   else if(y[1]==y[2]){
      x[3]=x[1];
      x[4]=x[2];
      y[3]=y[4]=y[1]+abs(x[1]-x[2]);
      if(y[3]>=-1000&&y[3]<=1000&&y[4]>=-1000&&y[4]<=1000){
         for(int i=3;i<=4;i++)cout<<x[i]<<" "<<y[i]<<" ";
         cout<<"\n";
         return 0;
      }
      x[3]=x[1];
      x[4]=x[2];
      y[3]=y[4]=y[1]-abs(x[1]-x[2]);
      for(int i=3;i<=4;i++)cout<<x[i]<<" "<<y[i]<<" ";
      cout<<"\n";
      return 0;
   }
   x[3]=x[1];
   y[3]=y[2];
   x[4]=x[2];
   y[4]=y[1];
   if(issq()==false){
      cout<<-1<<"\n";
      return 0;
   }
   for(int i=3;i<=4;i++)cout<<x[i]<<" "<<y[i]<<" ";
   cout<<"\n";
}
