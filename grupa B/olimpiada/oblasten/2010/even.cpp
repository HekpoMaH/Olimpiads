#include<iostream>
using namespace std;
int k;
int main()
{
    cin>>k;
    for(int i=1;i<=10;i++)
    {
        if(k%2==1)cout<<2*i*(k+1)+1<<" ";
        else cout<<i*(k+2)+1<<" ";
    }
    cout<<endl;
}
