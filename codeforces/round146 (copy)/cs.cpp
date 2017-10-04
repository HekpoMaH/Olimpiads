#include<iostream>
using namespace std;
int n,pr=1;
int nok(int a,int b,int c)
{
    for(int i=1;i<=a*b*c;i++)
    {
        if(i%a==0&&i%b==0&&i%c==0)return i;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                pr=max(pr,nok(i,j,k));
                //cout<<i<<" "<<j<<" "<<k<<" "<<nod(nod(i,j),k)<<endl;
            }
        }
    }
    cout<<pr<<endl;
    return 0;
}

