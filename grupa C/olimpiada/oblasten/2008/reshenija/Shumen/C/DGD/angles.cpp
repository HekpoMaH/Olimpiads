#include<cstdio>
int a[1000][1000],n,k,maxc,i1,j1,c;
int main()
{
    int i,j,q;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
                    for(j=0;j<n;j++) scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    c=0;
                                    int d=j+k,r=i+k;
                                    if(d>n)d=n;
                                    if(r>n)r=n;
                                    for(q=j+1;q<d;q++)
                                                      c+=a[i][q];
                                    for(q=i+1;q<r;q++)
                                                      c+=a[q][j];
                                    c+=a[i][j];
                                    if(c>maxc)
                                    {
                                              maxc=c;
                                              i1=i;
                                              j1=j;
                                    }
                    }
    }
    printf("%d %d\n",i1+1,j1+1);
    return 0;
}
