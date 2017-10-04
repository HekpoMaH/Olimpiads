#include <iostream>

using namespace std;

int main()
{
    long long n,m;
    cin>>m;
    cin>>n;
    int multi=1;
    while((m*multi+n*multi)%m!=0||
    (m*multi+n*multi)%n!=0)
    {
      multi++;
    }
    cout<<multi*2<<endl;
    return 0;
}
