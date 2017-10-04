#include<iostream>
using namespace std;
int main()
{
    int a[30];
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
            cin>>a[i];
    }
    int br=0,s=0;
    for(int i=0;i<=n-1;i++)
    {
            s+=a[i];
            br++;
    }
    double sr=0;
    sr=s/br;
    int br1=0;
    for(int i=0;i<=n-1;i++)
    {
            if(a[i]>sr){br1++;}
    }
    cout<<br1<<endl;
    system("pause");
    return 0;
} 
