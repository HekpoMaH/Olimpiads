#include <iostream>

using namespace std;

int main()
{
    int m,n,t;
    cin>>m>>n;
    t=(m+n)/2;
    if(m==1 && n==1)t=1;cout<<t;return 0;
    if(t%2==1)t=t-1;
    cout<<t<<endl;

    return 0;
}
