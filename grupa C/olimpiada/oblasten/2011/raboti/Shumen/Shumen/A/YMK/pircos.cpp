#include<iostream>
using namespace std;
long long a[20][20],xr,mini,maxi;
int main()
{
    long long n,v,v1,i,k;
    int j;
    scanf("%lld", &n);
    for(i=0;i<n;i++)
    {
        scanf("%lld", &v);
        xr=xr^v;
        j=0;
        v1=v;
        while(v1)
        {
            a[j][v1%10]=a[j][v1%10]^v;
            v1/=10;
            j++;
        }
    }
    k=0;
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            if(a[i][j]!=0)
                if(a[i][j]!=xr)
                {
                    if(k==0){ mini=a[i][j];k++;}
                    else
                    if(k==1 && mini!=a[i][j]){ maxi=a[i][j]; k++;}
                }
    if(mini>maxi)swap(mini,maxi);
    printf("%lld %lld \n", mini, maxi);
    return 0;
}

/*
10
14
7
21
9
14
17
17
7
19
9

*/

