#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int max=a[0],d;
    for(int i=0;i<n;i++)
    {
            if(a[i]>max){max=a[i];d=i;}
    }
    cout<<max<<" "<<d<<endl;
    system("pause");
    return 0;
}
