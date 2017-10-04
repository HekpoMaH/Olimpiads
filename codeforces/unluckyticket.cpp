#include<iostream>
#include<algorithm>
using namespace std;
string a,a1,a2;
int n,correct1,correct2,correct3,correct4;
int main()
{
    cin>>n;
    cin>>a;
    int x=1,y=1;
    for(int i=0;i<n;i++)a1+=a[i];
    for(int i=n;i<2*n;i++)a2+=a[i];
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    //cout<<a1<<" "<<a2<<endl;
    for(int i=0;i<n;i++)
    {
        
        if(a1[i]<=a2[i])x=0;
        if(a1[i]>=a2[i])y=0;
    }
    if(x==1||y==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
