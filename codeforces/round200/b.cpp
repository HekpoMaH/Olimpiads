#include<bits/stdc++.h>
using namespace std;
int a,b,c,br=0;
int main()
{
    cin>>a>>b>>c;
    for(int i=0;i<=a;i++)
    {
        if(b>=i)
        {
            if(c==a-i+b-i)
            {
                cout<<i<<" "<<b-i<<" "<<a-i<<endl;
                return 0;
            }
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}
