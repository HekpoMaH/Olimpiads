#include<iostream>
using namespace std;
int md[1000][1000],dm[1000][1000];
int n;
int mariedd[1000],ergen[1000];
int semd[1000],br;
int findmax(int kx)
{
    int mxd=0,mxdind=0;
    for(int i=1;i<=n;i++)if(md[kx][i]>mxd){mxd=md[kx][i];mxdind=i;}
    return mxdind;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ergen[i]=i;
        mariedd[i]=0;
        for(int j=1;j<=n;j++)md[i][j]=dm[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>md[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>dm[i][j];
    }
    int mx,k=1;
    while(k<=n)
    {
        //cout<<"teku6tmladej="<<k<<endl;
        mx=findmax(ergen[k]);
        //cout<<"mx="<<mx<<" ergen="<<ergen[k]<<" ismaried="<<mariedd[mx]<<endl;
        if(mariedd[mx]==0){semd[mx]=ergen[k];mariedd[mx]=1;k++;continue;}
        else
        {//cout<<"mx="<<mx<<" ergen="<<ergen[k]<<" ismaried="<<mariedd[mx];
            if(dm[mx][semd[mx]]<dm[mx][ergen[k]])
            {
                md[semd[mx]][mx]=0;
                swap(semd[mx],ergen[k]);//cout<<"mx="<<mx<<" ergen="<<ergen[k]<<" ismaried="<<mariedd[mx];
            }
            else 
            {
                md[ergen[k]][mx]=0;
                while(1)
                {
                    mx=findmax(ergen[k]);
                    //cout<<"mx="<<mx<<" ergen="<<ergen[k]<<" ismaried="<<mariedd[mx];
                    if(mariedd[mx]==0){semd[mx]=ergen[k];mariedd[mx]=1;k++;break;}
                    else
                    {
                        if(dm[mx][semd[mx]]<dm[mx][ergen[k]])
                        {
                            md[semd[mx]][mx]=0;
                            swap(semd[mx],ergen[k]);
                            break;
                        }
                    }
                    
                }
            }
        }
        //for(int i=1;i<=n;i++)cout<<"devoika="<<i<<" mladej="<<semd[i]<<endl;
    }
    for(int i=1;i<=n;i++)cout<<"devoika="<<i<<" mladej="<<semd[i]<<endl;
    return 0;
}