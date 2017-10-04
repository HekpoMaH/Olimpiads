#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int a[100009],br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1])br++;
        else br=1;
    }
    cout<<n-br<<endl;
}

