#include <iostream>
#include <conio.h>
using namespace std;
struct {
        bool s[30][30];
        int red[30];
        int kol[30];
        bool fl;
       }a[1002];
bool r[30][30];
int n;

bool ednn(int x)
{
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(r[i][j]!=a[x].s[i][j]) return 0;
    return 1;
}

bool edn(int x,int y)
{
    //zavurtane nadqsno
    for(int br=0;br<4;br++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                    r[j][n-1-i]=a[x].s[i][j];
        if(ednn(y)) { return 1; }
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            a[x].s[i][j]=r[i][j];
    }
    //zavurtane ogledalno
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        r[i][n-1-j]=a[x].s[i][j];
    if(ednn(y)) { return 1; }
    for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            a[x].s[i][j]=r[i][j];
    //zavurtane nadqsno
    for(int br=0;br<4;br++)
    {
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            r[j][n-1-i]=a[x].s[i][j];
        if(ednn(y)) { return 1; }
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            a[x].s[i][j]=r[i][j];
    }
    return 0;
}

int main ()
{
    int m;
    cin>>m>>n;
    getchar();
    char t[31];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        {
            gets(t);
            int u=strlen(t);
            for(int k=0;k<u;k++)
              if(t[k]=='1') { a[i].s[j][k]=1; a[i].red[j]++; a[i].red[k]++; }
                else a[i].s[j][k]=0;
        }
    for(int i=0;i<m;i++)
      for(int j=i+1;j<m;j++)
         if(!a[j].fl) if(edn(i,j)) { a[j].fl=1; a[i].fl=1; }
    int br=0;
    for(int i=0;i<m;i++)
      if(a[i].fl==0) br++;
    cout<<br<<endl;
    return 0;
}
