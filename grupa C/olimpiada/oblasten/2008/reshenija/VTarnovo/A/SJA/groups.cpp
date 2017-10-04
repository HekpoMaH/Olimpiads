#include <iostream>
#define MAX 1e12
using namespace std;

double DP[501][501], F[501][501];
int N, p;
double P[500];

double dp(int i, int k)
{
    if (DP[i][k] != MAX) return DP[i][k];
    
    int j;
    if (k != 1) j = i;
    else j = N - 1;
    
    for (; j < N - k + 1; j++) 
     DP[i][k] = min(DP[i][k], dp(j + 1, k - 1) + F[i][j]);
    
    return DP[i][k];
}

int main()
{
    cin >> N >> p;
    
    for (int i = 0; i <= N; i++)
     for (int j = 0; j <= N; j++)
      DP[i][j] = MAX;
    DP[N][0] = 0;
    
    for (int i = 0; i < N; i++)
     cin >> P[i];
    
    for (int i = 0; i < N; i++)
     for (int j = i; j < N; j++)
     {
           double S = 0;
           for (int i1 = i; i1 <= j; i1++)
            S += P[i1];
           double avg = S/(j - i + 1);
           
           for (int i1 = i; i1 <= j; i1++)
            F[i][j] += (avg - P[i1])*(avg - P[i1]);
    }
     
    cout << dp(0, p) << endl;
    //system("pause");
    return 0;
} 
