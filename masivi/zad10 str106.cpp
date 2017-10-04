//zad10 str 106
#include<iostream>
using namespace std;
int main()
{
    int a[100],b[100],c[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    int j=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
            if(a[i]<0){b[j]=a[i];j++;}
            if(a[i]>0){c[k]=a[i];k++;}
    } 
    for(int i=0;i<j;i++)
    {
            cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<k;i++)
    {
            cout<<c[i]<<" ";
    }                  
    cout<<endl;
    system("pause");
    return 0;
} 
