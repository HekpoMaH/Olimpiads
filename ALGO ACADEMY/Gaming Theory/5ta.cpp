#include<bits/stdc++.h>
using namespace std;
string pos[4];
int wx,wo,dr;
struct table
{
    string r[4];
};
void go(table x,int nahod)
{
    int brrx=0,brcx=0,brdx=0,brro=0,brco=0,brdo=0;
    for(int i=1;i<=3;i++)
    {
        if(x.r[i][0]==x.r[i][1]&&x.r[i][2]==x.r[i][0]&&x.r[i][0]=='X'){wx++;return;}
        if(x.r[i][0]==x.r[i][1]&&x.r[i][2]==x.r[i][0]&&x.r[i][0]=='O'){wo++;return;}
    }
    for(int i=0;i<3;i++)
    {
        if(x.r[2][i]==x.r[1][i]&&x.r[2][i]==x.r[3][i]&&x.r[1][i]=='X'){wx++;return;}
        if(x.r[2][i]==x.r[1][i]&&x.r[2][i]==x.r[3][i]&&x.r[1][i]=='O'){wo++;return;}
    }
    if(x.r[1][0]==x.r[2][1]&&x.r[1][0]==x.r[3][2]&&x.r[1][0]=='X'){wx++;return;}
    if(x.r[1][0]==x.r[2][1]&&x.r[1][0]==x.r[3][2]&&x.r[1][0]=='O'){wo++;return;}
    if(x.r[1][2]==x.r[2][1]&&x.r[1][2]==x.r[3][0]&&x.r[1][2]=='X'){wx++;return;}
    if(x.r[1][2]==x.r[2][1]&&x.r[1][2]==x.r[3][0]&&x.r[1][2]=='O'){wo++;return;}
    int l=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(x.r[i][j]=='-')
            {
                l=1;
                if(nahod==1)x.r[i][j]='X';
                else x.r[i][j]='O';
                go(x,3-nahod);
                x.r[i][j]='-';

            }
        }
    }
    if(l==0)dr++;
}
int main()
{
    cin>>pos[1];
    cin>>pos[2];
    cin>>pos[3];
    table str;
    str.r[1]=pos[1];
    str.r[2]=pos[2];
    str.r[3]=pos[3];
    int br=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<3;j++)if(pos[i][j]=='X')br++;
    }
    go(str,br%2+1);
    cout<<wx<<endl<<dr<<endl<<wo<<endl;
}
