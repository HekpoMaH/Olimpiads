#include <iostream>
#include<climits>
#include<cmath>
using namespace std;
int main(){
long g,n,a,b,i,j=INT_MAX;
cin>>n;
for(a=1;a<=n;a++){
	for(b=1;b<=n;b++){
		if(n==(a*b) && fabs(a-b)<j){j=fabs(a-b);i=a;g=b;}}}
		if(i<g)cout<<i<<' '<<g<<endl;
		else cout<<g<<' ' <<i<<endl;
    return 0;
}
