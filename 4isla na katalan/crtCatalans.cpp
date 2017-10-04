#include<iostream>
using namespace std;
int g;
int main()
{
    cin>>g;
    int r;
    r=1;
    for(int i=1;i<=g;i++)r=r*(2*g-i+1)/i;
    cout<<r/(g+1)<<endl;
}
