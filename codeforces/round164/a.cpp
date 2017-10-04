#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
int a[100],b[100],br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                if(a[i]==b[j])br++;
            }
        }
    }
    cout<<br<<endl;
}