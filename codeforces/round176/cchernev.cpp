#include<cstdio>
#include<iostream>
using namespace std;
int n,a[1001001],used[1001001];
int main()
{
    int p,i,br,j,p1,p2;
    scanf("%d",&n);
    if(n==1){printf("1\n");return 0;}
    if(n%4==0||n%4==1)
    {
        i=1;j=n;
        p1=1;
        p2=n;
        for(i=i;i<=n/2;i+=0)
        {
            cout<<p1<<" "<<p2<<endl;
            a[i]=p1+1;
            a[i+1]=p2;
            a[j]=p2-1;
            a[j-1]=p1;
            i+=2;
            j-=2;
            p1+=2;
            p2-=2;
        }
        if(n%4==1)a[n/2+1]=n/2+1;
        for(i=1;i<n;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    else printf("-1\n");
}
