/*
Task: ninja
Author: Nikolay Kostov
*/
#include <stdio.h>
#define MAXN 15
#define INIT_STATE_ON 1
#define INIT_STATE_OFF 0
using namespace std;
int dp[MAXN];
int N, initState;
int fromLeft, fromUp;
int main()
{
    scanf("%d", &N);
    scanf("%d", &initState);

    // first row, first column = first second
    dp[0] = 1;

    // first row
    for (int col = 1; col < N; col++)
    {
        scanf("%d", &initState);

        if (initState == INIT_STATE_ON && (dp[col-1] % 2) == 1)
            dp[col] = dp[col-1] + 1;
        else if (initState == INIT_STATE_OFF && (dp[col-1] % 2) == 0)
            dp[col] = dp[col-1] + 1;
        else dp[col] = dp[col-1] + 2;
    }

    for(int row = 1; row < N; row++)
    {
        // first column
        scanf("%d", &initState);
        if (initState == INIT_STATE_ON && (dp[0] % 2) == 1)
            dp[0] = dp[0] + 1;
        else if (initState == INIT_STATE_OFF && (dp[0] % 2) == 0)
            dp[0] = dp[0] + 1;
        else dp[0] = dp[0] + 2;

        // next columns
        for(int col = 1; col < N; col++)
        {
            scanf("%d", &initState);

            if (initState == INIT_STATE_ON && (dp[col-1] % 2) == 1)
                fromLeft = dp[col-1] + 1;
            else if (initState == INIT_STATE_OFF && (dp[col-1] % 2) == 0)
                fromLeft = dp[col-1] + 1;
            else fromLeft = dp[col-1] + 2;

            if (initState == INIT_STATE_ON && (dp[col] % 2) == 1)
                fromUp = dp[col] + 1;
            else if (initState == INIT_STATE_OFF && (dp[col] % 2) == 0)
                fromUp = dp[col] + 1;
            else fromUp = dp[col] + 2;

            dp[col] =  fromUp < fromLeft ? fromUp : fromLeft;
        }
    }

    printf("%d\n", dp[N-1]);

    return 0;
}
