#include <iostream>
using namespace std;
int n[1002][1002];
int main ( ) {
    int M, N, K, totalsum=0, sum, max=0, i, j, k, l;
    cin >> M >> N >> K;
    for (i=1;i<=M;i++)
        {
        for (j=1;j<=N;j++)
            {
            cin >> n[i][j];
            totalsum+=n[i][j];
            }
        }
    for (i=1;i<=M-k+2;i++)
        {
        for (j=1;j<=N-K+2;j++)
            {
            sum=0;
            for (k=i;k<=i+K-1;k++) for (l=j;l<=j+K-1;l++) sum+=n[k][l];
            if (max<=sum) max=sum;
            }
        }
    cout << totalsum-max << endl;
    return 0;
}
