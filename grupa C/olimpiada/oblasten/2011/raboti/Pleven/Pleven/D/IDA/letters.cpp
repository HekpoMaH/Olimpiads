#include<iostream>
#include<string.h>
using namespace std;
int main () {
long long i,n,b,d[40001],j,k,br1=0,br2=0,br3=0,br4=0,br=0;
string s[40001],g;
char a;
cin>>n>>a;
b=a;


 for(i=1;i<=n*4;i++){
 cin>>s[i];
 d[i]=s[i].size();

 }


 for(i=1;i<=n*4;i=i+4){
    g=s[i];
    k=g.size();
  if(g[0]==b || g[0]==b+32 || g[0]==b-32){br1++;}
  }


   for(i=2;i<=n*4;i=i+4){
    g=s[i];
    k=g.size();
    for(j=1;j<=k;j++){
   if(g[j]==b || g[j]==b+32 || g[j]==b-32){br2++;}
   }
   }


   for(i=3;i<=n*4;i=i+4){
    g=s[i];
    k=g.size();

    for(j=1;j<=k;j++){
   if(g[j]==b || g[j]==b+32 || g[j]==b-32){
   br++;
   if(br==2){br3++; br=0;}
   }
   }
   }


   for(i=4;i<=n*4;i=i+4){
    g=s[i];
    k=g.size();
    if(g[k-1]==b || g[k-1]==b+32 || g[k-1]==b-32){br4++;}
    }


cout<<br1<<" "<<br2<<" "<<br3<<" "<<br4;
cout<<endl;


return 0;
}

/*
3 a
Ani Miraj Masa Bala
Taralej toto Dani Kana
ananas pile ananas Tapa


//   cout<<g[0]<<" "<<g<<endl;

*/