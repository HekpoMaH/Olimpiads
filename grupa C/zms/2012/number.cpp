#include<iostream>
#include<cstdio>
using namespace std;
const long long maxs=9*100,maxp=9*9*100,maxlen=100;
int len[maxs+4][maxp+4],lastdig[maxs+4][maxp+3],numb[maxlen+4],sz;
int s,p,t;
int main()
{
    for(int i=0;i<=maxs;i++)for(int j=0;j<=maxp;j++){len[i][j]=-1;lastdig[i][j]=-1;}
    for(int i=1;i<=9;i++){len[i][i*i]=1;lastdig[i][i*i]=i;}
    for(int i=2;i<=maxs;i++)
        for(int j=2;j<=maxp;j++)
            if(len[i][j]==-1)
                for(int k=1;k<=9&&i-k>=0&&j-k*k>=0;k++)
                    if(len[i-k][j-k*k]!=-1&&(len[i][j]==-1||len[i-k][j-k*k]+1<len[i][j]))
                    {
                        len[i][j]=len[i-k][j-k*k]+1;
                        lastdig[i][j]=k;
                    }
    //cout<<len[9][15]<<endl;
    int f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&s,&p);
        if(s>maxs||p>maxp)printf("No solution\n");
        else if(len[s][p]==-1||len[s][p]>maxlen)printf("No solution\n");
        else
        {sz=0;
        while(!(s==0||p==0))
        {
            printf("%d",lastdig[s][p]);
            f=lastdig[s][p];
            s-=f;
            p-=f*f;
            //sz++;
        }
        //for(int i=0;i<sz;i++)printf("%d",numb[sz]);
        printf("\n");
        }
    }
}