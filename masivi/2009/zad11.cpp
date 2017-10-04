#include<iostream>
using namespace std;
int main()
{
    int a[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int x,br=0;
    cin>>x;
    for(int i=0;i<n;i++)
    {
            if(a[i]==x)br++;
    }
    if(br==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    system("pause");
    return 0;
}
