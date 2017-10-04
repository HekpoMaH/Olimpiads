#include<iostream>
using namespace std;
int n,m,a[2001][2001],used[2001],mn,pred[2001],sum;
int main(){
int i,j,k;
cin>>n>>m;
for(i=1;i<=m;i++){
    cin>>j>>k;
    if(!used[k]){
    a[j][0]++;
    a[j][a[j][0]]=k; used[k]=1; pred[k]=j;}
}
mn=a[1][0];
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(pred[j]==i)sum+=a[j][0];
    }if(sum>mn)mn=sum;
    sum=0;
}
cout<<mn<<endl;
    return 0;
}
