#include<iostream>
#include<string>
using namespace std;
string s[257],duma;
int m,n,row,col,ds,br;
int main/*a*/()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>s[i];
    }
    cin>>duma;
    ds=duma.size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            row=i;col=j;
            if(col+ds<=n)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    col++;
                }
            }
            row=i;col=j;
            if(col+ds<=n&&row+ds<=m)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    col++;
                    row++;
                }
            }
            row=i;col=j;
            if(row+ds<=m)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    row++;
                }
            }
            row=i;col=j;
            if(row+ds<=m&&col-ds+1>=0)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    row++;
                    col--;
                }
            }
            row=i;col=j;
            if(col-ds+1>=0)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    col--;
                }
            }
            row=i;col=j;
            if(col-ds+1>=0&&row-ds+1>=0)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    col--;row--;
                }
            }
            row=i;col=j;
            if(row-ds+1>=0)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    row--;
                }
            }
            row=i;col=j;
            if(row-ds+1>=0&&col+ds<=n)
            {
                br++;
                for(int k=0;k<ds;k++)
                {
                    if(duma[k]!=s[row][col]){br--;break;}
                    row--;col++;
                }
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
/*
asffdf
eds
*/