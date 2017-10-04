/*
Task: ninja
Author: Nikolay Kostov
*/
#include <iostream>
#define MAXN 1501
#define MAXTIME 2000000000
#define INIT_STATE_ON 1
#define INIT_STATE_OFF 0
using namespace std;

int N;
int matrix[MAXN][MAXN];
int bestAnswer = MAXTIME;

void bt(int time, int x, int y)
{
    // Check if the room is light
    if (matrix[x][y] == INIT_STATE_ON && (time % 2) == 1) return; // time = 1, 3, 5...
    if (matrix[x][y] == INIT_STATE_OFF && (time % 2) == 0) return; // time = 2, 4, 6...

    // Check if we have reached the target
    if (x == N - 1 && y == N - 1)
    {
        if (time < bestAnswer) bestAnswer = time;
        return;
    }

    // Don't wait and visit next cells
    if (x + 1 < N) bt(time + 1, x + 1, y);
    if (y + 1 < N) bt(time + 1, x, y + 1);

    // Wait 1 second and visit next cells
    if (x + 1 < N) bt(time + 2, x + 1, y);
    if (y + 1 < N) bt(time + 2, x, y + 1);
}

int main()
{
    // Read input
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Solve the task using backtracking
    bt(1, 0, 0);

    // Output the answer
    cout << bestAnswer << endl;

    return 0;
}
