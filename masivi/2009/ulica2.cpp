#include<iostream>
using namespace std;
int main()
{
    int a[200];
    int n;
    cin>>n;
    int br=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
            if(a[i]!=a[i-1])br++;
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
