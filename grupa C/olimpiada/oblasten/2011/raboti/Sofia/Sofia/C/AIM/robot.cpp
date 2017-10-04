#include<iostream>
using namespace std;
int table[100][100];
int pos[100][100];
int main()
{
    int m, n, r, k, t=1, sum=0, d, current=1, row, column;
    cin>>m>>n>>r>>k;
    d=k%2;
    row=(r-1)/n;
    column=(r-1)%n;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n; b++)
        {
            table[a][b]=t;
            if(row-a>=0) pos[a][b]=pos[a][b]+row-a;
            else pos[a][b]=pos[a][b]+a-row;
            if(column-b>=0) pos[a][b]=pos[a][b]+column-b;
            else pos[a][b]=pos[a][b]+b-column;
            if((pos[a][b]%2==d)&&(pos[a][b]<=k)) sum=sum+table[a][b];
            t++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
