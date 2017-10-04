#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int br=0;
    for(int i=0;i<n;i++)
    {
            if(a[i]%2==0)br++;
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
