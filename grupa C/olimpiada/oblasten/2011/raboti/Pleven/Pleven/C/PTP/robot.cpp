#include<stdio.h>
int a[100][100];
bool used[100][100];
int k,m,n,r,x0,y0;
long sum=0;
void buildTable() {
    int j=1;
    int x=0,y=0;
    while(j<=m*n) {
        if(r==j) {x0=x; y0=y;}
        a[x][y++]=j++;
        if(y==n) {
            y=0;
            x++;
        }
    }
}
void rec(int x,int y,int lvl=0) {
    if(lvl>k)
        return;
    if(lvl==k) {
        sum+=a[x][y];
        used[x][y]=true;
    }
    if(x<m-1 && !used[x+1][y]) rec(x+1,y,lvl+1);
    if(y<n-1 && !used[x][y+1]) rec(x,y+1,lvl+1);
    if(y>0 && !used[x][y-1]) rec(x,y-1,lvl+1);
    if(x>0 && !used[x-1][y]) rec(x-1,y,lvl+1);
}
int main() {
    int i,j,x,y;
    scanf("%d %d %d %d",&m,&n,&r,&k);
    buildTable();
    rec(x0,y0);
    printf("%ld\n",sum);
    return 0;
}
