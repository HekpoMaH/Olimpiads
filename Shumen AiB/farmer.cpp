#include<bits/stdc++.h>
using namespace std;
int a[2009][2009];
int sum[2009][2009],n,m;
int mi=9999,mi2,mj=9999,mj2,mx,mxio[9],mxi[9];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
        //cout<<i<<" "<<n<<endl;
    }
    //cout<<"r'<<endl"<<endl;
    int i1,j1,i,j;
    int lam=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            mi=mj=9999;mj2=mi2=0;lam=0;
            for(i1=i;i1<=n;i1++)
            {
                for(j1=j;j1<=n;j1++)
                {
                    if(a[i1][j1]==0)
                    {
                        lam=1;
                        mi=min(mi,i1);
                        mj=min(mj,j1);
                        mi2=max(mi2,i1);
                        mj2=max(mj2,j1);
                    }
                    if(lam==1&&sum[mi2][mj2]-sum[mi2][mj]-sum[mi][mj2]+sum[mi][mj]==0&&(i1-i+1)*(j1-j+1)>mx)
                    {
                        cout<<"i="<<i<<" j="<<j<<" i1="<<i1<<" j1="<<j1<<" mi="<<mi<<" mi2="<<mi2<<" mj="<<mj<<" mj2="<<mj2<<endl;
                        cout<<"their sum is "<<sum[mi2][mj2]-sum[mi2][mj]-sum[mi][mj2]+sum[mi][mj]<<endl;
                        mx=(i1-i+1)*(j1-j+1);
                        mxio[1]=mi;mxio[2]=mj;mxio[3]=mi2;mxio[4]=mj2;
                        mxi[1]=i;mxi[2]=j;mxi[3]=i1;mxi[4]=j1;
                    }
                }
            }

        }
    }
    cout<<mxio[1]<<" "<<mxio[2]<<" "<<mxio[3]<<" "<<mxio[4]<<endl;
    cout<<mxi[1]<<" "<<mxi[2]<<" "<<mxi[3]<<" "<<mxi[4]<<endl;
    cout<<mx<<endl;

}
