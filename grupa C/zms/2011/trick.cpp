#include<iostream>
#include<string>
using namespace std;
long long d,otg,a[200009][3],br;
char ch;
int main()
{
    ios::sync_with_stdio(false);
    while(1)
    {
        cin>>ch;
        cin>>d;
        if(ch=='+'){a[br][0]=d;a[br][1]=1;br++;}
        if(ch=='-'){a[br][0]=d;a[br][1]=2;br++;}
        if(ch=='*'){a[br][0]=d;a[br][1]=4;br++;}
        if(ch=='=')break;
    }
    for(long long i=br-1;i>=0;i--)
    {
        if(a[i][1]==1)d-=a[i][0];
        if(a[i][1]==2)d+=a[i][0];
        if(a[i][1]==4)d/=a[i][0];
    }
    cout<<d<<"\n";
    return 0;
}
