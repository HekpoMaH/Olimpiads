#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int x;
    cin>>x;
    int i=0;
    int l=0;
    while (i<n&&l==0)
    {
            if(a[i]==x)l++;
            i++;
    }
    if(l==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    system("pause");
    return 0;
}
