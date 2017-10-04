/*
Task: ninja
Author: Nikolay Kostov
*/
#include <stdio.h>
#define MAXN 15
#define INIT_STATE_ON 1
#define INIT_STATE_OFF 0
using namespace std;
char initRooms[MAXN][MAXN];
int dp[MAXN][MAXN];
int N;
int main()
{
    // Read input
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &initRooms[i][j]);
        }
    }

    // First second - top left room
    dp[0][0] = 1;

    // Zero row
    for (int col = 1; col < N; col++)
    {
        if (initRooms[0][col] == INIT_STATE_ON && (dp[0][col-1] % 2) == 1)
            dp[0][col] = dp[0][col-1] + 1;
        else if (initRooms[0][col] == INIT_STATE_OFF && (dp[0][col-1] % 2) == 0)
            dp[0][col] = dp[0][col-1] + 1;
        else dp[0][col] = dp[0][col-1] + 2;
    }

    // First col
    for (int row = 1; row < N; row++)
    {
        if (initRooms[row][0] == INIT_STATE_ON && (dp[row-1][0] % 2) == 1)
            dp[row][0] = dp[row-1][0] + 1;
        else if (initRooms[row][0] == INIT_STATE_OFF && (dp[row-1][0] % 2) == 0)
            dp[row][0] = dp[row-1][0] + 1;
        else dp[row][0] = dp[row-1][0] + 2;
    }

    // Using dynamic programming to find the answer
    int fromLeft, fromUp;
    for(int row = 1; row < N; row++)
    {
        for(int col = 1; col < N; col++)
        {
            if (initRooms[row][col] == INIT_STATE_ON && (dp[row][col-1] % 2) == 1)
                fromLeft = dp[row][col-1] + 1;
            else if (initRooms[row][col] == INIT_STATE_OFF && (dp[row][col-1] % 2) == 0)
                fromLeft = dp[row][col-1] + 1;
            else fromLeft = dp[row][col-1] + 2;

            if (initRooms[row][col] == INIT_STATE_ON && (dp[row-1][col] % 2) == 1)
                fromUp = dp[row-1][col] + 1;
            else if (initRooms[row][col] == INIT_STATE_OFF && (dp[row-1][col] % 2) == 0)
                fromUp = dp[row-1][col] + 1;
            else fromUp = dp[row-1][col] + 2;

            dp[row][col] =  fromUp < fromLeft ? fromUp : fromLeft;
        }
    }

    printf("%d\n", dp[N-1][N-1]);

    return 0;
}
