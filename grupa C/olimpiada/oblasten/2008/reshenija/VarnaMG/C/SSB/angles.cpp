#include<iostream>
using namespace std;
int n,k,a[1001][1001],mr,mc,ms;
int sum(int r,int c){
    int i,j,sm=0;
    if((r+k)<=n&&(c+k)<=n){
        for(i=r;i<=r+k;i++) sm+=a[i][c];
        for(i=c+1;i<=c+k;i++) sm+=a[r][i];
    }
    else if((r+k)<=n&&(c+k)>n){
        for(i=r;i<=r+k;i++) sm+=a[i][c];
        for(i=c+1;i<=n;i++) sm+=a[r][i];
    }
     else if((r+k)>n&&(c+k)<=n){
        for(i=r;i<=n;i++) sm+=a[i][c];
        for(i=c+1;i<=c+k;i++) sm+=a[r][i];
    }
    if((r+k)>n&&(c+k)>n){
        for(i=r;i<=n;i++) sm+=a[i][c];
        for(i=c+1;i<=n;i++) sm+=a[r][i];
    }
    return sm;
}
int main(){
    int i,j,sm;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
           sm=sum(i,j);
           if(sm>ms){ms=sm;mr=i;mc=j;}
        }
    }
    cout<<mr<<" "<<mc<<endl;
    return 0;
}
