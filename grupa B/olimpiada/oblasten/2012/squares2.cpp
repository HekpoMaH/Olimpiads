#include<bits/stdc++.h>
using namespace std;
int s;
vector<bool> a;//bithacks ftw++;
int main()
{
    cin>>s;
    a.resize(s+10);
    for(int i=0;i*i<=s;i++)
    {
        for(int j=i;j*j+i*i<=s;j++)a[i*i+j*j]=true;
    }
    int br=0;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]==true)br++;
        //cout<<i<<" "<<a[i]<<endl;
    }
    cout<<br<<endl;
}
