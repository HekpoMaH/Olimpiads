#include<bits/stdc++.h>
using namespace std;
const int nmax=410;
const int base=1000000000;
const int cmax=16;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
struct bignum{
   int a[cmax];
   bignum(){
      memset(a,0,sizeof(a));
   }
   bignum(int x){
      memset(a,0,sizeof(a));
      a[0]=x;
   }
   void add(const bignum &b){
      int x,y=0;
      for(int i=0;i<cmax;i++){
         x=a[i]+b.a[i]+y;
         a[i]=x%base;
         y=x/base;
      }
   }
   void print(){
      int i;
      for(i=cmax-1;i>0;i--){
         if(a[i])break;
      }
      printf("%d",a[i]);
      for(i--;i>=0;i--){
         printf("%.9d",a[i]);
      }
      printf("\n");
   }
};
int k;
char buf[nmax];
vector<int> a,b;
int lo[nmax],hi[nmax];
bignum dp[nmax][nmax][2][2];
int used[nmax][nmax][2][2];
void read(){
   scanf("%d",&k);
   scanf("%s",buf);
   for(int i=0;i<(int)strlen(buf);i++){
      a.pb(buf[i]-'0');
   }

   scanf("%s",buf);
   for(int i=0;i<(int)strlen(buf);i++){
      b.pb(buf[i]-'0');
   }
}
int div(vector<int> &a){
   vector<int> b;
   int cur=0;
   for(int i=0;i<(int)a.size();i++){
      cur=cur*10+a[i];
      if((int)b.size()||cur/2)b.pb(cur/2);
      cur%=2;
   }
   a=b;
   return cur;
}
bignum go(int left,int cur,int up,int down){
   if(!left){
      if(cur>=k){
         return bignum(1);
      }
      return bignum(0);
   }
   if(used[left][cur][up][down])
      return dp[left][cur][up][down];
   used[left][cur][up][down]=1;
   bignum ans=0;
   if(!(down&&lo[left]))ans.add(go(left-1,cur>=k ? k : 0 , up&(!hi[left]), down&(!lo[left])));
   if(!(up&&!hi[left]))ans.add(go(left-1,cur>=k ? k : cur+1 , up&(hi[left]), down&(lo[left])));
   dp[left][cur][up][down]=ans;
   return ans;
}
void solve(){
   if(k>400)printf("0\n");
   else{
      int n=0,m=0;
      while((int)a.size()){
         lo[++n]=div(a);
      }
      while((int)b.size()){
         hi[++m]=div(b);
      }
      go(m,0,1,1).print();
   }
}
int main(){
   read();
   solve();
}
