#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int nmax=1e6;
lli r1,r2,r3;
lli b[9];
vector<int> a[9];
int used[nmax];
vector<int> f;
void read(){
   r1=r2=r3=0;
   memset(used,0,sizeof(used));
   f.clear();
   for(int i=1;i<=3;i++){
      a[i].clear();
      int x;
      cin>>x;
      b[i]=x;
      for(int j=2;j*j<=x;j++){
         if(x%j==0){
            a[i].pb(j);
            used[j]++;
            while(x%j==0)x/=j;
         }
      }
      if(x>1){
         a[i].pb(x);
         used[x]++;
      }
   }
}
bool prime(int x){
   for(int i=2;i*i<=x;i++){
      if(x%i==0)return false;
   }
   return true;
}
void go(int x){
   if(r1>0&&r1+r2+r3<b[4]+b[5]+b[6])return;
   int cnt,bad;
   for(int i=1;i<x-1;i++){
      for(int j=i+1;j<x-1;j++){
         if(__gcd(b[i],__gcd(b[j],b[x-1]))>1)return;
         if(__gcd(b[i],b[j])==1&&__gcd(b[i],b[x-1])==1&&__gcd(b[j],b[x-1])==1)return;
      }
   }
   if(x==7){
      r1=b[4];
      r2=b[5];
      r3=b[6];
      return;
   }
   for(int i=0;i<(1<<(int)a[1].size());i++){
      for(int j=0;j<(1<<(int)a[2].size());j++){
         for(int k=0;k<(1<<(int)a[3].size());k++){
            b[x]=1;
            cnt=0;
            bad=0;
            for(int basi=1;basi<=3;basi++){
               int swag;
               if(basi==1)swag=i;
               if(basi==2)swag=j;
               if(basi==3)swag=k;
               for(int d=0;d<(int)a[basi].size();d++){
                  if((swag&(1<<d))){
                     if(used[a[basi][d]]==2)bad=1;
                     used[a[basi][d]]++;
                     cnt++;
                     a[x].pb(a[basi][d]);
                     b[x]*=a[basi][d];
                  }
               }
            }
            if(!bad){
               go(x+1);
               if(x>=5){
                  for(int d=4;d<=5;d++){
                     for(int e=0;e<2;e++){
                        if(!used[f[e]]){
                           if(d==5&&x==5)continue;
                           used[f[e]]=1;
                           b[d]*=f[e];
                           b[x]*=f[e];
                           go(x+1);
                           if(x==6&&d==4&&!used[f[2]]){
                              b[5]*=f[2];
                              b[x]*=f[2];
                              go(x+1);
                              b[5]/=f[2];
                              b[x]/=f[2];
                           }
                           b[d]/=f[e];
                           b[x]/=f[e];
                           used[f[e]]=0;
                        }
                     }
                  }
               }
            }
            while(cnt--){
               used[a[x].back()]--;
               a[x].pop_back();
            }
         }
      }
   }
}
void solve(){
   b[4]=b[5]=b[6]=1;
   for(int i=1;i<=3;i++){
      sort(a[i].begin(),a[i].end());
      for(int j=0;j<(int)a[i].size();j++){
         if(used[a[i][j]]==2){
            a[i].erase(a[i].begin()+j);
            j--;
         }
      }
      while((int)a[i].size()>3)a[i].pop_back();
   }
   for(int i=2;i<=100000;i++){
      if(!used[i]&&prime(i)&&(int)f.size()<6){
         f.push_back(i);
      }
   }
   r1=-1;
   go(4);//it
   if(r1<0)cout<<0<<"\n";
   else cout<<r1<<" "<<r2<<" "<<r3<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();

   read();
   solve();
}
