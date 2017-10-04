#include<cstdio>
int m,n,k,table[1024][1024],minn,curr;
int main()
{
     scanf("%d%d%d",&n,&m,&k);
     for(int i=1;i<=n;++i)
          for(int j=1;j<=m;++j)
          {
               scanf("%d",&curr);
               table[i][j]=curr+table[i][j-1]+table[i-1][j]-table[i-1][j-1];
          }
     minn=table[n][m];
     for(int i=k;i<=n;++i)
          for(int j=k;j<=m;++j)
          {
               curr=table[n][m]-table[i][j]-table[i-k][j-k]+table[i][j-k]+table[i-k][j];
               if(curr<minn)minn=curr;
          }
     printf("%d\n",minn);
     return 0;
}
