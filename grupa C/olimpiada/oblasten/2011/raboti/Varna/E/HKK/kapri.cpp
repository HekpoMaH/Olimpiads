#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n,k,i,b=0,l=0,p,q,z;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>k;
        for(p=1,l=0;k%p!=k;l++)p=p*10;
        z=pow(10.,l);
        p=(k*k)%z;
        q=(k*k)/z;
        if(q==0)q=(k*k)/(z-10);
        if(p+q==k)b++;
        }
        cout<<b<<endl;
return 0;}
