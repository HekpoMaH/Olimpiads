#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
struct sword{
   int god,num;
};
bool cmp(sword fi,sword se){
   return fi.god>se.god;
}
int n;
sword sw[nmax];
int ans[nmax];
int k;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>sw[i].god;
      sw[i].num=i;
   }
   sort(sw+1,sw+n+1,cmp);
   int uk1=1,uk2=2;
   memset(ans,-1,sizeof(ans));
   ans[sw[uk1].num]=0;
   int br=0;
   while(uk2<=n){
      while(uk2<=n&&sw[uk2].god+k>sw[uk1].god)uk2++;
      if(uk2<=n){
         br++;
         ans[sw[uk2].num]=sw[uk1].num;
         uk2++;
      }
      if(br==2)uk1++,br=0;
   }
   for(int i=1;i<=n;i++)
      if(ans[i]==-1){
         cout<<-1<<"\n";
         exit(0);
      }
   for(int i=1;i<=n;i++)
      cout<<ans[i]<<" ";
   cout<<"\n";
}
