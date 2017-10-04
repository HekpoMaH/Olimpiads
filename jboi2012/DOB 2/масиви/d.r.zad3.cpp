#include<iostream>
using namespace std;
int main()
{
    double a[25];
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
            cin>>a[i];
    }
    int max=0;
    for(int i=0;i<=n-1;i++)
    {
            if(a[i]>max){max=a[i];}
    }
    int br=0;
    for(int i=0;i<=n-1;i++)
    {
            if(a[i]==max){br++;}
    }        
    cout<<br<<endl;
    system("pause");
    return 0;
}
