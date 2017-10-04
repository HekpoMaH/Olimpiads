#include<iostream>
using namespace std;
int main()
{
    int n,a[1001];
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=0;
    for(int i=1;i<=n;i++)
    {
            for(int k=i;k<=n;k+=i)
            {
                    if(a[k]==0)a[k]=1;
                    else a[k]=0;
            }
    }
    int br=0;
    for(int i=1;i<=n;i++)if(a[i]==1)br++;
    cout<<br<<endl;
    system("pause");
    return 0;
}
