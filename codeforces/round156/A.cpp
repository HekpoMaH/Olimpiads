#include<iostream>
using namespace std;
int n,x,a,b,c;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(i%3==0)a+=x;
        if(i%3==1)b+=x;
        if(i%3==2)c+=x;
    }
    if(a>b&&a>c)cout<<"chest"<<endl;
    if(b>a&&b>c)cout<<"biceps"<<endl;
    if(c>b&&c>a)cout<<"back"<<endl;
}
