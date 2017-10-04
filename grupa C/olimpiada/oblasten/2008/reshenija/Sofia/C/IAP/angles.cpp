#include<iostream>
using namespace std;
int main()
{
    int N, K, C, cagal, cx, cy, tablica[N][N], x, y;
    cin>>N>>K; 
    for(x=0; x<N; x++)
    for(y=0; y<N; y++)
    cin>>tablica[x][y];
    for(cx=0; cx<N; cx++){
    for(cy=0; cy<N; cy++)
    cagal=tablica[cx][cy];
    }
    return 0;
}
