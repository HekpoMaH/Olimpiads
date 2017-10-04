#include<bits/stdc++.h>
using namespace std;
const int nmax=100009;
int obraten[nmax];//YMCA
int p;
int main(){
   cin>>p;
   obraten[0]=-1;
   obraten[1]=1;
   for(int i=2;i<p;i++){
      obraten[i]=(-(p/i)*obraten[p%i])%p;
      obraten[i]+=p;
      //obraten[i]%=p;
      //assert(0<=obraten[i]&&obraten[i]<p);
   }
   for(int i=1;i<p;i++)cout<<obraten[i]<<" ";
   cout<<"\n";
}
