//zad 8
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
    int br=0;
    for(int i=0;i<n;i++)
    {
            if(a[i]>0){br++;}
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
