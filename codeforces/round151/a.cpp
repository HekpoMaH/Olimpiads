#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[100];
int main()
{
    cin>>n;
    if(n==1||n==2){cout<<-1<<endl;return 0;}
    for(int i=n;i>1;i--)cout<<i<<" ";
    cout<<1<<endl;
    return 0;
}
