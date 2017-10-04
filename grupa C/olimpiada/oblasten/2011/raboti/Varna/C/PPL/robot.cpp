#include<iostream>
using namespace std;

int k=0,h,c[105][105],ch[1005]={0},m,n,a2,b2;

void rek(int a, int b){
   if(k==h && ch[c[a][b]]==0){ch[c[a][b]]=1; k=0; rek(a2,b2);}
else if(a-1>=0 && ch[c[a-1][b]]==0) { k++; rek(a-1,b); }
   else if(b-1>=0 && ch[c[a][b-1]]==0) {k++; rek(a,b-1);}
else if(a+1<m && ch[c[a+1][b]]==0) { k++; rek(a+1,b);}
   else if(b+1<n && ch[c[a][b+1]]==0) { k++; rek(a,b+1);}
   else return;
}

int main(){

int r,i,j,p=1,i2,j2,s=0;

cin>>m>>n>>r>>h;

for(i=0;i<m;i++){
for(j=0;j<n;j++){
c[i][j]=p;
if(p==r) {i2=i; j2=j;}
p++; }}

a2=i2; b2=j2;
rek(i2,j2);

for(i=1;i<=m*n;i++){
if(ch[i]==1) s=s+i;}

cout<<s;

return 0;
}
