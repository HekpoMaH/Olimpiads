#include<iostream>
#include<math.h>
using namespace std;
int main(){

long long s,br=0,c[101],i,n;

cin>>s>>n;

for(i=0;i<n;i++){
cin>>c[i];}

sort(c,c+n);

for(i=n-1;i>=0;i--){
if(s==0) break;
else if(s>=c[i]){br=s/c[i]+br; s=s%c[i];}}

cout<<br;

return 0;
}
