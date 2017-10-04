#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,w,x,c,br;
int main()
{
    cin>>a>>b>>w>>x>>c;
    do
    {
        c--;
        if(b>=x)b-=x;
        else a--,b=w-(x-b);
        br++;
        cout<<a<<" "<<b<<" "<<w<<" "<<x<<" "<<c<<endl;
    }while(!(c<=a));
    cout<<br<<endl;
}
