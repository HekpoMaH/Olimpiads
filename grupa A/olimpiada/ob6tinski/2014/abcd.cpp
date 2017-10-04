#include<bits/stdc++.h>
using namespace std;
char cons[32],vow[9];
char syllable[200][9];
typedef long long lli;
lli n;
int c,v,p;
void read(){
   char a[100],s[100];
   cin>>a>>s>>n;
   for(int i=0;a[i];i++){
      if(strchr(s,a[i]))vow[v++]=a[i];
      else cons[c++]=a[i];
   }
   for(int i=0;i<c;i++){
      for(int j=0;j<v;j++){
         syllable[p][0]=cons[i];
         syllable[p++][1]=vow[j];
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   lli t,s,d;
   int num[32];
   read();
   t=0;s=0;d=1;
   while(s<n){
      t++;
      d*=p;
      s+=d;
      cout<<s<<" "<<p<<" "<<d<<" "<<n<<"\n";
   }
   s-=d;
   s=n-1-s;
   for(int i=t-1;i>=0;i--){
      num[i]=s%p;
      s/=p;
      cout<<num[i]<<" ";
   }
   cout<<"\n";
   for(int i=0;i<t;i++){
      cout<<syllable[(int)num[i]];
   }
   cout<<"\n";
}
