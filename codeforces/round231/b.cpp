#include<bits/stdc++.h>
using namespace std;
int p;
long long st[11];
int main()
{
    st[0]=1;
    for(int i=1;i<=11;i++)st[i]=10*st[i-1];
    cin>>p;
    for(int x=1;x<=9;x++)
    {
        for(long long a=x*st[p-1];a<st[p];a++)
        {
            //cout<<a<<" "<<(a%10)*st[p-1]+a/10<<endl;
            if(a*x==(a%10)*st[p-1]+a/10)
            {
                cout<<"x="<<x<<" a="<<a<<endl;
                break;
            }
        }
    }
}
