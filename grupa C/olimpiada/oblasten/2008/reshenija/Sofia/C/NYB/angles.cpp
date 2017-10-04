#include<iostream>
int a[1000][1000],N,K,i,j,l,m,r,c,B,b[1000][1000];
using namespace std;
int main()
{
    cin>>N>>K;
    for(i=1;i<=N;i++){
      for(j=1;j<=N;j++){
        cin>>a[i][j];
      }
    }
    for(i=1;i<=N;i++) {
      for(j=1;j<=N;j++) {
        for(l=j+1;l<=N;l++){
          b[i][j]+=a[i][l];
          B++;
          if(B>=K) break;
        }
        for(l=i+1;l<=N;l++) {
          b[i][j]+=a[l][j];
          B++;
          if(B>=K) break;
        }
      }
    }
    m=b[N][N];
    for(i=N;i>0;i--){
      for(j=N;j>0;j--){
        if (b[i][j]>=m) {
          m=b[i][j];
          r=i;
          c=j;
        }
      }
   }
   cout<<r<<" "<<c<<"\n";
return 0;
}
