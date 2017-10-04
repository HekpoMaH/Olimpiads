#include <iostream>
using namespace std;
int main()
{
    int an,n,k,i,j,l;
    int maxi,maxj,maxan;
    int a[716][716];
    maxi=1;maxj=1;maxan=0;
    cin>>n>>k;
    an=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        cin>>a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            {
            an=a[i][j];
            if (i+k>n) for (l=i+1;l<=n;l++) an+=a[l][j];
            else
            for (l=i+1;l<=i+k;l++) an+=a[l][j];
            
            if (j+k>n) for (l=j+1;l<=n;l++) an+=a[i][l];
            else
            for (l=j+1;l<=j+k;l++) an+=a[i][l];
            if (an>maxan) {maxan=an;maxi=i;maxj=j;}
            }
    cout<<maxi<<' '<<maxj<<endl;
return 0;
}
