#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[150];
    cin>>n;
    int i=0;
    for(i=0;i<n;i++)cin>>a[i];
    int s=0;
    i=0;
    while(a[i]<0)
    {
            s+=a[i];
            i++;
    }
    cout<<a[i]<<" ";
    cout<<s<<endl;
    system("pause");
    return 0;
}
