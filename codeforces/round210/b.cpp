#include<bits/stdc++.h>
using namespace std;
int n,k,a[100009];
int nod(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)a[i]=i;
    do
    {

        int br=0;
        for(int i=1;i<=n;i++)if(nod(i,a[i])!=1)br++;
        if(br==k)
        {
            for(int i=1;i<=n;i++)cout<<a[i]<<" ";
            cout<<endl;
            exit(0);
        }
    }while(next_permutation(a+1,a+n+1));
    cout<<-1<<endl;
}
