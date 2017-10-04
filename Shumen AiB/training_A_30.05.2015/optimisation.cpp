#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long lli;
typedef pair<lli ,lli > pii;
lli m[nmax];
lli w2[nmax];
lli w[nmax];
lli p[nmax];
lli N;
lli M;
pii sl[nmax];
lli a[nmax];
lli b[nmax];
lli ans;
void mergesort(lli a[],lli lef,lli righ){
   //cout<<lef<<" "<<righ<<"\n";
   //for(int i=1;i<=N;i++)cout<<a[i]<<"\n";
   //cout<<"\n";
   if(righ-lef+1<=1)return;
   lli mid=(lef+righ)/2;
   mergesort(a,lef,mid);
   mergesort(a,mid+1,righ);
   for(int i=lef;i<=righ;i++){
      b[i]=a[i];
   }
   lli i=lef,j=mid+1,k=lef;
   while(i<=mid&&j<=righ){
      if(b[i]<=b[j]){
         a[k]=b[i];i++;k++;
      }
      else{
         ans+=mid-i+1;
         a[k]=b[j];
         j++;
         k++;
      }
   }
   while(i<=mid){
      a[k]=b[i];i++;k++;
   }
   while(j<=righ){
      a[k]=b[j];j++;k++;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>M>>N;
   for(int i=1;i<=N;i++){
      cin>>m[i];
   }
   for(int i=1;i<=M;i++){
      int k;
      cin>>k;
      for(int j=1;j<=k;j++){
         lli x;
         cin>>x;
         w2[i]+=m[x];
         p[x]=i;
      }
   }
   for(int i=1;i<=N;i++){
      w[i]=w2[p[i]];
      sl[i]=mp(m[i],-(w[i]-m[i]));
      //cout<<w[i]<<" ";
   }
   //cout<<"\n";
   sort(sl+1,sl+1+N);
   lli br=0;
   for(int i=1;i<=N;i++){
      //sl[i].se=-(sl[i].se-sl[i].fi);
      //cout<<sl[i].fi<<" "<<sl[i].se<<"\n";

      br++;
      a[br]=sl[i].se;
   }
   br=0;
   //for(int i=1;i<=N;i++)cin>>a[i];
   //for(int i=1;i<=N;i++){
      //cout<<a[i]<<" ";
   //   for(int j=i+1;j<=N;j++){
   //      if(a[i]>a[j])br++;
   //   }
   //}
   //cout<<"\n";
   mergesort(a,1,N);
   //assert(br==ans);
   cout<<ans<<"\n";
   //cout<<br<<"\n";
}
