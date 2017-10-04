/*
TASK: trade
LANG: C++
*/

#include<cstdio>
int n;
float mas[1<<20][1<<20];
float raz[1<<20][1<<20];
float nums[1<<20];
void solve()
{
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        int k=(i+2)%n;
        raz[k][i]=2*(mas[j][k]+mas[i][j]);
    }
    for(int g=2;g<n;g+=2)
        for(int i=0;i<n;i++)
        {
            int j=(i+g)%n;
            int k=(j+g)%n;
            raz[i][k]=raz[i][j]+raz[j][k];
        }
    for(int k=1;k<=n;k++)
    {
        int i=k-1;
        int j=k%n;
        nums[j]=(mas[j][j]-raz[i][j])/2.;
    }
    for(int i=0;i<n;i++)
    {
        if(i)printf(" ");
        printf("%f",nums[i]);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        float c;
        scanf("%d%d%f",&a,&b,&c);
        mas[a-1][b-1]=c;
    }
    if(n%2==0)printf("too many");
    else solve();
    printf("\n");
    return 0;
}
