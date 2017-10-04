#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int er[10009],tab[303][303],cn,iy,ix,px,py,sp,sw,br,wx,wy,wx2,wy2,used[303][303];int x,y;

void solve()
{
    for(int i=1;i<=300;i++)
    {
        for(int j=1;j<=300;j++)
        {
            if(tab[i][j]==x)wx=i,wy=j;
            if(tab[i][j]==y)wx2=i,wy2=j;
        }
    }
    //cout<<wx<<" "<<wy<<" "<<wx2<<" "<<wy2<<endl;
    ix=x;iy=x;pair<int,int> cr;queue<pair<int,int> > q;
    q.push(make_pair(wx,wy));memset(used,0,sizeof(used));used[wx][wy]=1;
    //cout<<wx<<" "<<wy<<" "<<wx2<<" "<<wy2<<endl;
    while(!q.empty())
    {
        cr=q.front();q.pop();
        //cout<<cr.first<<" "<<cr.second<<endl;
        if(tab[cr.first][cr.second]==y)break;
        if(er[tab[cr.first-1][cr.second]]==0)
        {
            if(used[cr.first-1][cr.second]==0&&cr.first>1)
            {
                q.push(make_pair(cr.first-1,cr.second));
                used[cr.first-1][cr.second]=used[cr.first][cr.second]+1;
            }
        }

        if(er[tab[cr.first][cr.second-1]]==0)
        {
            if(used[cr.first][cr.second-1]==0&&cr.second>1)
            {
                q.push(make_pair(cr.first,cr.second-1));
                used[cr.first][cr.second-1]=used[cr.first][cr.second]+1;
            }
        }

        if(er[tab[cr.first+1][cr.second]]==0)
        {
            if(used[cr.first+1][cr.second]==0&&cr.first<300)
            {
                q.push(make_pair(cr.first+1,cr.second));
                used[cr.first+1][cr.second]=used[cr.first][cr.second]+1;
            }
        }

        if(er[tab[cr.first][cr.second+1]]==0)
        {
            if(used[cr.first][cr.second+1]==0&&cr.second<300)
            {
                q.push(make_pair(cr.first,cr.second+1));
                used[cr.first][cr.second+1]=used[cr.first][cr.second]+1;
            }
        }
    }
    if(used[wx2][wy2]==0)cout<<"impossible"<<endl;
    else cout<<used[wx2][wy2]-1<<endl;
}
int main()
{
    for(int i=1;i<=10009;i++)er[i]=1;
    er[1]=0;
    er[2]=1;
    for(int i=1;i<=10000;i++)
    {
        if(er[i]==1)for(int j=i+i;j<=10000;j+=i)er[j]=0;
    }
    //cout<<er[2]<<" "<<er[3]<<" "<<er[4]<<" "<<er[5]<<" "<<er[12]<<" "<<er[13]<<endl;
    ix=150;iy=150;
    cn=1;sp=1;
    px=0;py=1;
    while(cn!=101*101+4)
    {
        tab[ix][iy]=cn;//if(cn==x)wx=ix,wy=iy;
        //if(cn==y)wx2=ix,wy2=iy;
        ix+=px;iy+=py;
        cn++;
        br++;
        if(br==sp)
        {
            sw++;br=0;
            if(px==0&&py==1){px=-1;py=0;}
            else if(px==-1&&py==0){px=0;py=-1;}
            else if(px==0&&py==-1){px=1;py=0;}
            else px=0,py=1;
        }
        if(sw==2){sw=0;sp++;}
        //cout<<ix<<" "<<iy<<" "<<cn<<endl;
    }
    int wtf=0;
    while(cin>>x>>y)
    {
        wtf++;
        cout<<"Case "<<wtf<<": ";
        solve();
    }
}
