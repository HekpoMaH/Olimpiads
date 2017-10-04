#include<cstdio>
int n,m,r,k,x,y,total,dis;
int cabs(int ftw)
{return ftw<0?(-ftw):ftw;}
int main()
{
     scanf("%d%d%d%d",&n,&m,&r,&k);
     x=(r-1)/m;y=(r-1)%m;
     for(int i=0;i<n;++i)
          for(int j=0;j<m;++j)
          {
               dis=cabs(i-x)+cabs(j-y);
               if((dis<=k)&&((dis%2)==(k%2)))
                    total+=i*m+j+1;
          }
     printf("%d\n",total);
     return 0;
}
