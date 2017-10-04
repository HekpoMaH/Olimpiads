/*
ID: dobrikg1
PROG: ariprog
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
const int nmax=259;
int n,m;
int bisquares[2*nmax*nmax];
bool hassol=0;
int main(){
   freopen("ariprog.in","r",stdin);
   freopen("ariprog.out","w",stdout);
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int p=0;p<=m;p++){
      for(int q=0;q<=m;q++){
         bisquares[p*p+q*q]=1;
      }
   }
   int ffs=ceil((2.0*m*m+1.0)/(n-1.0));
   for(int b=1;b<ffs;b++){
      int ffs2=2*m*m-(n-1)*b+1;
      for(int a=0;a<ffs2;a++){
         for(int i=0;i<n;i++){
            if(!bisquares[a+b*i])break;
            if(i==n-1){
               cout<<a<<" "<<b<<endl;
               hassol=1;
            }
         }
      }
   }
   if(!hassol)cout<<"NONE\n";
}
