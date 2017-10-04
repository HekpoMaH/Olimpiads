#include <iostream>
using namespace std;
int a[1001][1001];
int main ( ) {
    long long int m, n, r, k, x, y, sum=0, i, j;
    cin >> m >> n >> r >> k;
    for (i=1;i<=m;i++)
        {
        for (j=1;j<=n;j++)
            {
            a[i+400][j+400]=n*(i-1)+j;
            }
        }
    /*
    for (i=1;i<=m;i++)
        {
        for (j=1;j<=n-1;j++)
            {
            cout << a[i+400][j+400] << " ";
            }
        cout << a[i+400][j+400] << endl;
        }
    */
    for (i=1;i<=m;i++)
        {
        for (j=1;j<=n;j++)
            {
            if (a[i+400][j+400]==r)
                {
                x=i+400;
                y=i+400;
                break;
                }
            }
        }
    if (k%2==0)
        {
        sum=r;
        for (i=x;i>=x-k;i--)
            {
            for (j=y;j>=y-k;j--)
                {
                if ((((x-i)+(y-j))<=k) && (((x-i)+(y-j))%2==0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        for (i=x;i<=x+k;i++)
            {
            for (j=y;j<=y+k;j++)
                {
                if ((((i-x)+(j-y))<=k) && (((i-x)+(j-y))%2==0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        for (i=x-1;i>=x-k;i--)
            {
            for (j=y+1;j<=y+k;j++)
                {
                if ((((x-i)+(j-y))<=k) && (((x-i)+(j-y))%2==0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        for (i=x+1;i<=x+k;i++)
            {
            for (j=y-1;j>=y-k;j--)
                {
                if ((((i-x)+(y-j))<=k) && (((i-x)+(y-j))%2==0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        sum=sum-2*r;
        }
    else
        {
        for (i=x;i>=x-k;i--)
            {
            for (j=y;j>=y-k;j--)
                {
                if ((((x-i)+(y-j))<=k) && (((x-i)+(y-j))%2!=0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        for (i=x;i<=x+k;i++)
            {
            for (j=y;j<=y+k;j++)
                {
                if ((((i-x)+(j-y))<=k) && (((i-x)+(j-y))%2!=0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        for (i=x-1;i>=x-k;i--)
            {
            for (j=y+1;j<=y+k;j++)
                {
                if ((((x-i)+(j-y))<=k) && (((x-i)+(j-y))%2!=0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        for (i=x+1;i<=x+k;i++)
            {
            for (j=y-1;j>=y-k;j--)
                {
                if ((((i-x)+(y-j))<=k) && (((i-x)+(y-j))%2!=0))
                    {
                    sum+=a[i][j];
                    }
                }
            }
        }
    cout << sum << endl;
    return 0;
}
