#include<iostream>
using namespace std;
int n,a,b,br;
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        if(i>a&&n-i<=b)br++;
    }
    cout<<br<<endl;
    return 0;
}
