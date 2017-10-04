#include<stdio.h>
int main() {
    int m,n,k,a[100][100],i,j,rx=0,ry=0,sum=0,cursum,minsum=1000000;
    scanf("%d %d %d",&m,&n,&k);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
            sum+=a[i][j];
        }
    while(1) {
        cursum=0;
        for(i=rx;i<rx+k;i++)
            for(j=ry;j<ry+k;j++)
                cursum+=a[i][j];
        if(sum-cursum<minsum)
            minsum=sum-cursum;
        ry++;
        if(ry+k>n) {
            ry=0;
            rx++;
        }
        if(rx+k>m)
            break;
    }
    printf("%d\n",minsum);
    return 0;
}
