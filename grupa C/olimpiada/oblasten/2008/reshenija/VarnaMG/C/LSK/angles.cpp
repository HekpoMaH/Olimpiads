#include<iostream>
using namespace std;
int main()
{
    int N, K;
    cin>>N>>K;
    int a[N][N], sum=0, max=0, red;
    for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) cin>>a[i][j];
    for(int i=N-K-1;i<N;i++)
    {
            for(int j=i;j<N;j++) sum=sum+a[i][j];
            for(int j=i-1;j<N;j++) sum=sum+a[j][i];
            if(max<sum){red=i; max=sum;}
            sum=0;
    }
    cout<<red+1<<" "<<red+1<<endl;
    return 0;
}
