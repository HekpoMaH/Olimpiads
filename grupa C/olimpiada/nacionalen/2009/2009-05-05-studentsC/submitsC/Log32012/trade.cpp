/*
TASK: trade
LANG: C++
*/
#include<iostream>
using namespace std;
long n,i,a,b;
double c,tr[10001][10001];
int main()
{
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
             scanf("%d%d%lf",&a,&b,&c);
             tr[a][b]=c;
             tr[b][a]=c;
    }
    if(n==3) {
    printf("%.2lf ",tr[1][2]+tr[1][n]-tr[2][3]);
    for(i=2; i<=n-2; i++)
    {
             printf("%.2lf ",tr[i][i+1]+tr[i][i-1]-tr[i+1][i+2]);
    }
    printf("%.2lf %.2lf\n",tr[n-1][n]+tr[n-1][n-2]-tr[n][1],tr[n][1]+tr[n][n-1]-tr[1][2]);
    }
    else if(n>=4&&n<=1000) {cout<<"impossible"<<endl;}
    else {cout<<"too many"<<endl;}
    //system ("PAUSE");
    return 0;
}
