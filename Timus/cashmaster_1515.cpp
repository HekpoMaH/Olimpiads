#include<iostream>
using namespace std;
int b[102],mx,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]>mx+1)
        {
            cout<<mx+1<<endl;
            return 0;
        }
        else mx+=b[i];
    }
    cout<<mx+1<<endl;
    return 0;
}