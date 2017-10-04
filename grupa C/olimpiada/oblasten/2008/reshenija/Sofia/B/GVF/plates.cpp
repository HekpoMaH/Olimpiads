#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    char b[30][1000];
    double a[30][1000];
    int n,m,br=1,temp=1;
    cin>>m>>n;
    for (int i=0;i<m;i++)
        for (int j=0;j<n*n;j++)
            cin>>b[i][j];
    for (int i=0;i<m;i++)
        for (int p=1,j=0;p<=n;p=p*10,j++)
                a[i][j]=(b[i][j]-48)*p;
    for (int i=0;i<m;i++)
    {
        if (br<temp)
        {
            br=temp;
            temp=0;
        }
        for (int j=i;j<m;j++)
            for (int p=0;p<n;p++)
                if (a[i][p]==a[i][0]) temp++;
    }
    cout<<br<<endl;
    return 0;
}

