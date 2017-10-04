#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
#define pb push_back
int finito;
int sal[3][nmax];
vector<int> vsal[3][nmax];
int cntsal[3];
int b[nmax];
int n;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>sal[1][i];
   }
}
void makenwsal(){
   int ukb=n;
   b[ukb]=sal[1][n];
   sal[2][n]=sal[1][n];
   for(int i=n-1;i>=1;i--){
      while(ukb<=n&&sal[1][i]>=b[ukb])ukb++;
      if(ukb==n+1){
         ukb=n;
         b[ukb]=sal[1][i];
         sal[2][i]=sal[1][i];
      }
      else{
         sal[2][i]=(sal[1][i]+b[ukb])/2;
         ukb--;
         b[ukb]=sal[1][i];
      }
      if(sal[1][i]!=sal[2][i])finito=0;
   }
}
void clearsal(int x){
   for(int i=1;i<nmax;i++)
      vsal[x][i].clear();
   cntsal[x]=0;
}
void makegroup(int x,int y){
   clearsal(x);
   for(int i=1;i<=n;i++){
      vsal[x][sal[y][i]].pb(i);
      if(vsal[x][sal[y][i]].size()==1)cntsal[x]++;
   }
}
bool chekdiff(){
   makegroup(2,2);
   if(cntsal[1]!=cntsal[2])return false;
   int fp=300,sp=300;
   for(int i=1;i<=cntsal[2];i++){
      while(vsal[1][fp].size()==0)fp++;
      while(vsal[2][sp].size()==0)sp++;
      if(vsal[1][fp].size()!=vsal[2][sp].size())return false;
      for(int j=0;j<vsal[1][fp].size();j++){
         if(vsal[1][fp][j]!=vsal[2][sp][j])return false;
      }
   }
   return true;
}
void transfersal(){
   for(int i=1;i<nmax;i++){
      sal[1][i]=sal[2][i];
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   makegroup(1,1);
   int it=0;
   while(!finito){
      it++;
      finito=0;
      makenwsal();
      if(it==13){
         finito=1;
      }
      if(finito==0){
         if(chekdiff()==0)finito=1;
      }
      //cout<<"---------\n";
      //cout<<chekdiff()<<"\n";
      //for(int i=1;i<=n;i++){
      //   cout<<sal[2][i]<<"\n";
      //}
      if(finito==0)transfersal();
   }
   for(int i=1;i<=n;i++){
      cout<<sal[1][i]<<"\n";
   }
}
