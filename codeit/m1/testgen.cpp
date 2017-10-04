#include<bits/stdc++.h>
using namespace std;
int n,m,a[309][309];
int main()
{
    srand(time(0));
    cin>>n>>m;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream fin("graph.in");
    ofstream fout("graph2.in");
    fout<<n<<" "<<m<<endl;
    for(int i=1;i<=m;i++)
    {
        fout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%100+1<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j){fout<<0<<" ";continue;}
            if(i<j)a[i][j]=a[j][i]=rand()%10+1;
            fout<<a[i][j]<<" ";
        }
        fout<<endl;
    }
}