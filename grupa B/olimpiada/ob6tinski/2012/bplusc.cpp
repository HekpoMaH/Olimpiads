#include<iostream>
#include<algorithm>
using namespace std;
int a[100],b[100],br,s[100];
void sbor()
{
    for(int i=br;i>=1;i--)
    {
        a[i]+=b[i];
        if(a[i]>=10)a[i]-=10,a[i-1]++;
    }
    if(a[0]!=0)cout<<a[0];
    for(int i=1;i<=br;i++)cout<<a[i];
    cout<<endl;
}
int main()
{
    char c;
    while(cin>>c)
    {
        br++;
        a[br]=c-'0';
        b[br]=c-'0';
    }
    sort(a+1,a+br+1);sort(b+1,b+br+1);
    reverse(b+1,b+br+1);

    int idx=1;
    while(a[idx]==0)idx++;
    //idx++;
    swap(a[idx],a[1]);//for(int i=1;i<=br;i++)cout<<a[i];
    //cout<<endl;
    //for(int i=1;i<=br;i++)cout<<b[i];
    //cout<<endl;
    sbor();
}
