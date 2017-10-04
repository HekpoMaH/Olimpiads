#include <iostream>
using namespace std;

int rotac(int a[][30][30], int b[][30][30], int n, int p)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
                b[p][i][j]=a[p][j][n-i-1];
        }
    return 0;
}

int obr(int a[][30][30], int n, int p)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n/2; j++)
        {
                a[p][i][j]=a[p][i][n-j-1];
        }
    return 0;   
}

int sr(int a[][30][30], int b[][30][30], int c[][30][30], int n, int p, int br)
{
    int k=1,s;
    for(int z=0; z<br; z++)
       for(int l=0; l<8; l++)
       {
          if(l==0)
          { 
              s=0;
              for(int i=0; i<n; i++)
                 for(int j=0; j<n; j++)
                 {
                     if(a[p][i][j]==c[z][i][j])
                     {
                         s++;
                     }
                 }
              if(s==n*n)
              {
                 k=0; 
                 break;        
              }
          }  
          else
          {
              s=0;
              for(int i=0; i<n; i++)
                 for(int j=0; j<n; j++)
                 {
                    if(b[p][i][j]==c[z][i][j])
                    {
                        s++;
                    }
                 }
              if(s==n*n)
              {
                   k=0; 
                   break;
              }
          }
          if(l>0&&l<4)
              rotac(a,b,n,p);
          if(l==4)
              obr(a,n,p);
          if(l>4&&l<8)
              rotac(a,b,n,p);
       }
    if(k==1)
    {
        br++;
        for(int i=0; i<n; i++)
           for(int j=0; j<n; j++)
           {
              c[br][i][j] = a[p][i][j];
           }   
    }
    return 0;
} 

int main()
{
    int b[1000][30][30],c[1000][30][30];
    int br=1,a[1000][30][30],m,n;    
    cin >> m >> n;
    for(int l=0; l<m; l++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin >> a[l][i][j];
            }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            c[0][i][j]=a[0][i][j];
        }       
    for(int p=0; p<m; p++)
    {
        sr(a,b,c,n,p,br);
    }
    cout << br;
    return 0;    
}
