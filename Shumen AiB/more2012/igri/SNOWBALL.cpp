#include<iostream>
#include<cstring>
using namespace std;
int n;
int sg[203],used[203];
int xr,lef,righ;
int main()
{
    cin>>n;
    sg[0]=0;
    sg[1]=1;
    sg[2]=1;
    sg[3]=2;
    sg[4]=0;
    
    for(int i=5;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        used[sg[i-2]]=1;
        used[sg[i-3]]=1;
        lef=1;righ=i-4;
        while(lef<=righ)
        {
            xr=sg[lef]^sg[righ];
            used[xr]=1;
            lef++;
            righ--;
        }
        for(int j=0;j<=203;j++)
        {
            if(used[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<i<<" "<<sg[i]<<endl;
    if(sg[n]!=0)cout<<"Snowwhite"<<endl;
    else cout<<"Rudolff"<<endl;
    return 0;
}