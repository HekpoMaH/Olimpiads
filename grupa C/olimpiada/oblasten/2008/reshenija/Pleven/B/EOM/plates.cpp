#include<iostream.h>
long m,n,a[30003][103],h,h1,flag,br,p,broi;
char q[1003];
int main()
{ long i,j,t,t1;
  cin>>m>>n;
  for(i=1;i<=m*n;i++)
  { cin>>q;
    for(j=1;j<=n;j++) a[i][j]=q[j-1]-48;
  }
  p=n*n;  
  for(i=1;i<=m;i++)
  { if (i==1) h=1;
    else h=(i-1)*n+1; 
    for(j=i+1;j<=m;j++)
    { flag=0;
      h1=(j-1)*n+1;
      if (a[h][n]==a[h1][n])
      { br=0;
        for(t=1;t<=n;t++)
         for(t1=1;t1<=n;t1++)
          if (a[h-1+t][t1]==a[h1-1+t][t1]) br++;
        if (br==p) flag=1; 
      } 
      if (flag==1) break;    
      if (a[h][n]==a[j*n][n])
      { br=0;
        for(t=1;t<=n;t++)
         for(t1=1;t1<=n;t1++)
          if (a[i*n-t1+1][t]==a[h1-1+t][t1]) br++;
        if (br==p) flag=1; 
      }
      if (flag==1) break;
      if (a[h][n]==a[j*n][1])
      { br=0;
        for(t=1;t<=n;t++)
         for(t1=1;t1<=n;t1++)
          if (a[i*n-t+1][n-t1+1]==a[h1-1+t][t1]) br++;
        if (br==p) flag=1;     
      }
      if (flag==1) break;
      if (a[h][n]==a[h1][1])
      { br=0;
        for(t=1;t<=n;t++)
         for(t1=1;t1<=n;t1++)
          if (a[i*n-n+t1][n-t+1]==a[h1-1+t][t1]) br++;
        if (br==p) flag=1;     
      }
      if (flag==1) break;
      if (flag==0) broi++;
    }
  }
  broi++;
  cout<<broi<<endl;
return 0;
} 
