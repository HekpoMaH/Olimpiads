#include<iostream>
using namespace std;

int c[1005][1005],k;

int p(int a, int b){
int s=0,i,j;

for(i=a;i<=a+k-1;i++){
for(j=b;j<=b+k-1;j++){
s=s+c[i][j];}}

return s;}

int main(){

int m,n,mx=0,bs=0,g,i,j;
cin>>m>>n>>k;

for(i=0;i<m;i++){
for(j=0;j<n;j++){
cin>>c[i][j]; bs=bs+c[i][j];}}

for(i=0;i<=m-k;i++){
for(j=0;j<=n-k;j++){
g=p(i,j);
if(g>mx) mx=g;}}

cout<<bs-mx;

return 0;
}
