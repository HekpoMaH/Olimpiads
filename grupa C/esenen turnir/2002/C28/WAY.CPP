#include<stdio.h>
#include<conio.h>
int main() {
int m[4][46],a,b,n,A,B;
printf("");
scanf("%d",&n);
for (b=1;b<=n*(n-1)/2;b++){
printf("");
scanf("%d%d%d",&m[1][b],&m[2][b],&m[3][b]);
}
scanf("%d%d",&A,&B);
for (b=1;b<=n*(n-1)/2;b++){
if((A==m[1][b]||A==m[2][b])&&(B==m[1][b]||B==m[2][b])&&m[3][b]==0)printf("2\n%d %d",A,B);
}

return 0;
}