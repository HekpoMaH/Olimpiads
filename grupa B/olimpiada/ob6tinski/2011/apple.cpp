#include<bits/stdc++.h>
using namespace std;
int x;
int res(int xx)
{
    if(xx<=2)return xx;
    if(xx%3==0)return 3*res(xx/3)+1;
    if(xx%3==1)return res(xx-1)+1;
    if(xx%3==2)return res(xx-2)+2;
}
int main()
{
    cin>>x;
    cout<<res(x)<<endl;
}
