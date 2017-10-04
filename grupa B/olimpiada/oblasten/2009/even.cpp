#include<iostream>
using namespace std;
long long k;
int main()
{
    cin>>k;
    for(int i=1;i<=10;i++)
    {
        if(k%2==1)cout<<(long long)((long long)2*i*(k+1)+1)<<" ";
        else cout<<(long long)((long long)i*(k+2)+1)<<" ";
    }
    cout<<endl;
}
