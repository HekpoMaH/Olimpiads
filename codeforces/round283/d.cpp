#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
#define mp make_pair
const int nmax=1e6+9;
int a1[nmax];
int a2[nmax];
int b1[nmax],b2[nmax];
set<pair<int,int> > ans;
int n;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=1e6;i++)a1[i]=a2[i]=inf;
   memset(b1,0,sizeof(b1));
   memset(b2,0,sizeof(b2));
   int x,y;
   x=y=0;
   int b;
   for(int i=1;i<=n;i++){
      cin>>b;
      if(b==1){
         a1[++x]=i;
      }
      if(b==2){
         a2[++y]=i;
      }
      b1[i]=x;
      b2[i]=y;
   }
   for(int i=1;i<=n;i++){
      bool fl=true;
      int p1,p2;
      p1=p2=0;
      int s1,s2;
      s1=s2=0;
      while(1){
         if(a1[p1+i]==inf&&a2[p2+i]==inf){
            break;
         }
         if(a1[p1+i]<a2[p2+i]){
            s1++;
            p1+=i;
            p2=b2[a1[p1]];
         }
         else if(a1[p1+i]>a2[p2+i]){
            s2++;
            p2+=i;
            p1=b1[a2[p2]];
         }
      }
      if(p1+p2==n){
         if(s1>s2&&b==1){
            ans.insert(mp(s1,i));
         }
         else if(s1<s2&&b==2){
            ans.insert(mp(s2,i));
         }
      }
   }
   cout<<ans.size()<<"\n";
   for(set<pair<int,int> >::iterator it=ans.begin();it!=ans.end();it++){
      cout<<it->first<<" "<<it->second<<"\n";
   }
}
