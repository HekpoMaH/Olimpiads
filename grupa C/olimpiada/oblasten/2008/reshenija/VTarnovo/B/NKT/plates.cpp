#include <iostream>

using namespace std;

int main()
{
    int m,n,a[100][100],br=0,p=0,c,v,e;
    cin >> m >> n;
    
    for(int i=0;i<=m-1;i++)
     for(int j=0;j<=n-1;j++)
      cin >> a[i][j];
    
    for(int i=0;i<=m-1;i++)
     for(int j=0;j<=n-2;j++)
     {  
             v=a[i][j]+a[i][j+1];
             while (v>0)
             {
                   c=v%10;
                   v=v/10;                                       
                   if(c>=2)p=1;
             }
             if(p==1)br=br+2;
             p=0;
      }
      
    cout << br << endl;
    
    cin >> e;
    return 0;
}

