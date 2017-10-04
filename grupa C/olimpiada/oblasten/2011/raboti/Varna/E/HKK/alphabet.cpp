#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    unsigned m,n,i,p=0;
    char k,n1,n2;
    cin>>n>>m;
    n1='a'+n-1;
    n2='A'+n-1;
    for(i=1;i<=m;i++){
        cin>>k;
        if(k==n1||k==n2)p=i;}
        if(p!=0)cout<<"win "<<p<<endl;
        else cout<<"lose"<<endl;
    return 0;}
