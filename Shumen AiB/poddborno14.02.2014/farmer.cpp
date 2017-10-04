#include<bits/stdc++.h>
using namespace std;
int a[2009][2009];
int sum[2009][2009],n,m;
int mi=9999,mi2,mj=9999,mj2,mx,mxio[9],mxi[9];
set<pair<int,int> >zeros;
string ts;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ts;//cout<<"ts="<<ts<<endl;
        for(int j=1;j<=m;j++)
        {
            if(ts[j-1]=='1')a[i][j]=1;//cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
        //cout<<i<<" "<<n<<endl;
    }
    //cout<<"r'<<endl"<<endl;
    int i1,j1,i,j;
    int lam=0;
    set<pair<int,int> >::iterator it;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(i1=i;i1<=n;i1++)
            {
                for(j1=j;j1<=m;j1++)
                {
                    lam=0;
                    mi=mj=9999;mi2=mj2=0;
                    if((i1-i+1)*(j1-j+1)<=mx)continue;
                    for(int i2=i;i2<=i1;i2++)
                    {
                        for(int j2=j;j2<=j1;j2++)
                        {
                            if(a[i2][j2]==0)
                            {
                                lam=1;
                                mj=min(mj,j2);
                                mi=min(mi,i2);
                                mi2=max(mi2,i2);
                                mj2=max(mj2,j2);
                            }
                        }
                    }
                    /*if(i==1&&j==1&&i1==3&&j1==4)
                    {
                        cout<<"i="<<i<<" j="<<j<<" i1="<<i1<<" j1="<<j1<<" mi="<<mi<<" mj="<<mj<<" mi2="<<mi2<<" mj2="<<mj2<<endl;
                        cout<<"their sum isss "<<sum[mi2][mj2]<<"-"<<sum[mi2][mj-1]<<"-"<<sum[mi-1][mj2]<<"+"<<sum[mi-1][mj-1]<<"="<<sum[mi2][mj2]-sum[mi2][mj-1]-sum[mi-1][mj2]+sum[mi-1][mj-1]<<endl;
                    }*/
                    if(lam==1&&sum[mi2][mj2]-sum[mi2][mj-1]-sum[mi-1][mj2]+sum[mi-1][mj-1]==0&&(i1-i+1)*(j1-j+1)>mx)
                    {
                        //cout<<"i="<<i<<" j="<<j<<" i1="<<i1<<" j1="<<j1<<" mi="<<mi<<" mj="<<mj<<" mi2="<<mi2<<" mj2="<<mj2<<endl;
                        //cout<<"their sum is "<<sum[mi2][mj2]<<"-"<<sum[mi2][mj-1]<<"-"<<sum[mi-1][mj2]<<"+"<<sum[mi-1][mj-1]<<"="<<sum[mi2][mj2]-sum[mi2][mj-1]-sum[mi-1][mj2]+sum[mi-1][mj-1]<<endl;
                        mx=(i1-i+1)*(j1-j+1);
                        mxio[1]=mi;mxio[2]=mj;mxio[3]=mi2;mxio[4]=mj2;
                        mxi[1]=i;mxi[2]=j;mxi[3]=i1;mxi[4]=j1;
                    }
                }

            }
            //zeros.clear();
        }
    }
    cout<<mxio[1]<<" "<<mxio[2]<<" "<<mxio[3]<<" "<<mxio[4]<<endl;
    cout<<mxi[1]<<" "<<mxi[2]<<" "<<mxi[3]<<" "<<mxi[4]<<endl;
    cout<<mx<<endl;

}
