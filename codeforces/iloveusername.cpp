#include<iostream>
using namespace std;
int n,a,mx,mn=10001,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a>mx)
        {
            mx=a;
            if(i!=1)br++;
        }
        if(a<mn)
        {
            if(i!=1)br++;
            mn=a;
        }
    }
    cout<<br<<endl;
    return 0;
}
