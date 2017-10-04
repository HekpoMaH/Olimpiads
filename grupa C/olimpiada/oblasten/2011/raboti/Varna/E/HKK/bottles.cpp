#include <iostream>
using namespace std;
int main() {
    unsigned m,n,i;
    cin>>m>>n;
    if(m>n) i=m;
    else i=n;
    for( ; ;i++)if(i%m==0&&i%n==0&&i%(m+n)==0)break;
    cout<<i*2/(m+n)<<endl;
    return 0;}
