#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int n;
    double a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    double max=a[0],br=0;
    for(int i=0;i<n;i++)
    {
            if(a[i]>max){max=a[i];}
    }
    for(int i=0;i<n;i++)
    {
            if(a[i]==max){br+=1;}
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
