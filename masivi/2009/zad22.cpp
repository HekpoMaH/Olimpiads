#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int s=0,c;
    int br=0;
    for(int i=0;i<n;i++)
    {
            a[i]=abs(a[i]);
            while(a[i]>0)
            {
                         c=a[i]%10;
                         s+=c;
                         a[i]/=10;
            }
            if(s>10)br+=1;
            s=0;
    }
    if(br==0)cout<<"No"<<endl;
    else cout<<br<<endl;
    system("pause");
    return 0;
}
