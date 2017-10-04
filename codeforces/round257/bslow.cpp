#include<bits/stdc++.h>
using namespace std;
struct mat{
   int a[6][6];
};
const int mod=1e9+7;
mat matrica;
mat umn(mat x,mat y){
   mat re;
   for(int i=1;i<=2;i++){
      for(int j=1;j<=2;j++){
         int sum=0;
         for(int k=1;k<=2;k++){
            sum=(mod+sum+(mod+x.a[i][k]*y.a[k][j])%mod)%mod;
         }
         re.a[i][j]=sum;
      }
   }
   return re;
}
void fastpow(int stepen){
   mat dw=matrica;
   mat ans=matrica;
   while(stepen!=0){
      if(stepen&1)ans=umn(ans,dw);
      dw=umn(dw,dw);
      stepen>>=1;
      for(int i=1;i<=2;i++){
         for(int j=1;j<=2;j++){
            cout<<ans.a[i][j]<<" ";
         }
         cout<<"\n";
      }
   }
   cout<<(ans.a[1][1]+ans.a[1][2])%mod<<"\n";
}
int main(){
   int x,y,n;
   cin>>x>>y>>n;
   int f[100000];
   f[1]=x;
   f[2]=y;
   int end;
   for(int i=3;i<=min(n,100000);i++){
      f[i]=(mod+f[i-1]-f[i-2])%mod;
      
   }
   for(int i=1;i<=n;i++){
      cout<<f[i]<<" ";
   }
   cout<<"\n";
   if(n<=999999){
      cout<<f[n]%mod<<"\n";
      return 0;
   }
   int beg=0,per=0;
   for(int i=1;i<=n;i++){
      cout<<f[i]<<" ";
   }
   cout<<"\n";
   cout<<f[n]%mod<<"\n";
}
