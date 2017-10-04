#include<iostream>
#include<string>
using namespace std;
int n,m,b[30][30],c[30][30],br;
bool a[1001][900],used[1001];
char ch;
int preo(int k)
{
    int j=0,t=0;
    for(int i=0;i<n*n;i++)
    {
        b[j][t]=a[k][i];
        t++;
        if(t==n){t=0;j++;}
    }
}
int preob(int k)
{
    int j=0,t=0;
    for(int i=0;i<n*n;i++)
    {
        c[j][t]=a[k][i];
        t++;
        if(t==n){t=0;j++;}
    }
}
int obr()
{
    int d[30][30];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    d[i][j]=c[n-j-1][i];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    c[i][j]=d[i][j];
}
bool srav()
{
    int p=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(b[i][j]!=c[i][j]){p=1;break;}
    if(p)return false;
    return true;
}
int main()
{
cin>>m>>n;
    int x;
    for(int i=0;i<m;i++)
    {
    for(int g=0;g<n;g++)
    {
    for(int j=0;j<n;j++)
    {
    cin.get(ch);a[i][j]=ch-'0';
    }
    cin.get(ch);
    }
    }
    for(int i=0;i<m;i++)
    {
    if(!used[i])
    {
        br++;
        preo(i);
        for(int j=i+1;j<m;j++)
        {
            int z=0;
            preob(j);
            if(srav()){used[j]=1;z=1;}
            if(!z)
            {
                obr();
                if(srav()){used[j]=1;z=1;}
            }
            if(!z)
            {
                obr();
                if(srav()){used[j]=1;z=1;}
            }
            if(!z)
            {
                obr();
                if(srav()){used[j]=1;z=1;}
            }
        }
    }
    }
    cout<<br<<endl;
    return 0;
}
            
