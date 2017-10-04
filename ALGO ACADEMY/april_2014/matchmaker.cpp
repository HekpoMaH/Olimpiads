#include<bits/stdc++.h>
using namespace std;
const int nmax=259;
struct person{
   string name;
   int ninterests;
   string interests[150];
};
person males[nmax];
person females[nmax];
int n;
int br1,br2;
inline bool cmp(person ed,person dv){
   return ed.name<dv.name;
}
inline int getscore(int man,int woman){
   int br=0;
   for(int i=1;i<=males[man].ninterests;i++){
      for(int j=1;j<=females[woman].ninterests;j++){
         if(males[man].interests[i]==females[woman].interests[j])br++;
      }
   }
   return br;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      string s1,s2;
      int x;
      cin>>s1>>s2;
      if(s2=="m"){
         males[++br1].name=s1;
         cin>>x;
         males[br1].ninterests=x;
         for(int j=1;j<=x;j++){
            cin>>males[br1].interests[j];
         }
      }
      if(s2=="f"){
         females[++br2].name=s1;
         cin>>x;
         females[br2].ninterests=x;
         for(int j=1;j<=x;j++){
            cin>>females[br2].interests[j];
         }
      }
   }
   int mx=0;
   string n1,n2;
   for(int i=1;i<=br1;i++){
      for(int j=1;j<=br2;j++){
         int sc=getscore(i,j);
         if(sc>mx){
            mx=sc;
            n1=males[i].name;
            n2=females[j].name;
         }
         if(sc==mx){
            if(males[i].name<=n1){
               mx=sc;
               n1=males[i].name;
               n2=females[j].name;
            }
         }
      }
   }
   if(mx==1){
      cout<<n1<<" and "<<n2<<" have "<<mx<<" common interest!\n";
   }
   if(mx!=1){
      cout<<n1<<" and "<<n2<<" have "<<mx<<" common interests!\n";
   }
}
