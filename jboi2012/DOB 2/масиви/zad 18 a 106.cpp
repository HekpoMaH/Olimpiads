//zad 18 a) str 106
#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    for(int i=n-1;i>=0;i--)
    {
            cout<<a[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}   
