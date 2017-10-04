#include<iostream>
using namespace std;
int s;const int smax=20000002;
int a[smax],br;
int main()
{
    cin>>s;
    for(int i=1;i*i<=s;i++)
    {
        for(int j=0;j*j+i*i<=s&&j<=i;j++)a[i*i+j*j]++;
    }
    for(int i=1;i<=s;i++)if(a[i]>0)br++;
    cout<<br<<endl;
}
