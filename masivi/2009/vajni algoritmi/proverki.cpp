#include<iostream>
using namespace std;
int main()
{
    int a[100],n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    //proverka 1
    int l=0;
    i=1;
    while(l==0&&i<=n)
    {
                     if(a[i]==0)l=1;
                     i++;
    }
    if(l==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //proverka 2
    i=1;
    l=0;
    while(l==0&&i<=n)
    {
                     if(a[i]>=a[i+1])l=1;
                     i++;
    }
    if(l==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //proverka 3
    i=1;
    l=0;
    while(l==0&&i<=n)
    {
                     for(int k=i+1;k<=n;k++)
                     {
                             if(a[i]==a[k])l=1;
                     }
                     i++;
    }
    if(l==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //proverka 4
    int maxr=0;
    for(i=1;i<=n;i++)
    {
                     for(int k=i+1;k<=n;k++)
                     {
                             if(abs(a[i]-a[k])>maxr)maxr=abs(a[i]-a[k]);
                     }
    }
    cout<<maxr<<endl;
    system("pause");
    return 0;
}
