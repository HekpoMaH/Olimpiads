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
    int sr=0,sb=0,br=0;
    for(int i=0;i<=n-1;i++)
    {
            sb=sb+a[i];
            br++;
    }
    sr=sb/br;
    int br2=0;
    for(int i=0;i<=n-1;i++)
    {
            if(a[i]>sr){br2++;}
    } 
    cout<<br2<<endl;

    system("pause");
    return 0;
}       
