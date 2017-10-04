#include<iostream>
using namespace std;
long n,i,j,c[101][101],a[101],b[101];
int main () {
cin>>n;
for(i=1;i<=n;i++) {
   cin>>a[i];
}
for(i=1;i<=n;i++) {
   cin>>b[i];
}
for(i=1;i<=n;i++) {
    c[2][i]=a[i]+b[n-i+1];
}
for(i=1;i<=n;i++) {
    c[1][i]=a[i]+b[i];
}
for(i=1;i<=2;i++) {
   sort(c[i]+1,c[i]+n+1);
}
if(c[1][1]>=c[2][1]) {
cout<<c[1][1]<<endl;
}
else {
   cout<<c[2][1]<<endl;
}
return 0;
}