#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    double s=0;
    int br=0;
    for(int i=0;i<n;i++)s+=a[i];
    s=s/n;
    for(int i=0;i<n;i++)
    {
            if(a[i]>s){br+=1;}
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
