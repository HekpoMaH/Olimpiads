#include <iostream>
using namespace std;
int m[1000][1001];
int main()
{
    int N,K;
    cin >> N >> K;
    int s;
    for(int i=0;i<N;i++)
    {
     s=0;
     for(int j=0;j<N;j++) { cin >> m[i][j]; s+=m[i][j]; }
     m[i][N]=s;
    }
    int s1=0,s2=0,maxs=0,x,y;
    for(int i=0;i<N;i++)
    {
        s=0;
        for(int j=0;j<N;j++)
        {
            s2=0;
            s1=m[i][N]-s;
            if(i+1<=N) for(int h=i;h<=i+K;h++) { if(h>N) break; s2+=m[h][j]; }
            if(maxs<s1+s2-m[i][j]) { maxs=s1+s2; x=i; y=j; }
            s+=m[i][j];
        }
    }
    cout << x+1 << " " << y+1 << endl;
    return 0;
}
