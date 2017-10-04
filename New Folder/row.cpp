#include<iostream>
using namespace std;
int main()
{
    int n;
    long long int a[1000],min=10000,max=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
            if(a[i]<min){min=a[i];}
            if(a[i]>max){max=a[i];}
    }
    double s;
    s=((max/3)*2)+(min/3);
    for(int j=0;j<n;j++)
    {
            if(a[j]<=s){cout<<j+1<<endl;break;}
    }
    system("pause");
    return 0;
}
