#include<iostream>
using namespace std;
int k,l,m,n,d,br;
int main()
{
    cin>>k>>l>>m>>n;
    cin>>d;
    for(int i=1;i<=d;i++)
    {
        if((i%k==0)||(i%l==0)||(i%m==0)||(i%n==0))br++;
    }
    cout<<br<<endl;
    return 0;
}