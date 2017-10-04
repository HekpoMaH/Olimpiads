#include <iostream>
using namespace std;

int maxDifferance = 0;

int main ()
{

    int N;
    cin >> N;

    int highsOne[100], highsTwo[100];
    cin >> highsOne[0];

    int maxStickOne = highsOne[0];

    for (int i = 1; i < N; i ++)
    {
        cin >> highsOne[i];

        if (highsOne[i] > maxStickOne)
        {
            maxStickOne = highsOne[i];
        }
    }

    cin >> highsTwo[0];

    int maxStickTwo = highsTwo[0];

    for (int i = 1; i < N; i ++)
    {
        cin >> highsTwo[i];

        if (highsTwo[i] > maxStickTwo)
        {
            maxStickTwo = highsTwo[i];
        }
    }

    int index;

    int differances[100];

    for (int i = 0; i < N; i ++)
    {
        differances[i] = (maxStickOne - highsOne[i]) + (maxStickTwo - highsTwo[i]);

        if (maxDifferance < differances[i])
        {
            maxDifferance = differances[i];
            index = i;
        }
    }

    int maxLength = highsOne[index] + highsTwo[index];

    int highsOne_two[100];

    for (int i = 0; i < N; i ++)
    {
        highsOne_two[i] = highsOne[N - i - 1];
    }

    maxDifferance = 0;

    for (int i = 0; i < N; i ++)
    {
        differances[i] = (maxStickOne - highsOne_two[i]) + (maxStickTwo - highsTwo[i]);

        if (maxDifferance < differances[i])
        {
            maxDifferance = differances[i];
            index = i;
        }
    }

    if (maxLength > highsOne_two[index] + highsTwo[index])
    {
        cout << maxLength << endl;
    } else
    {
        cout << highsOne_two[index] + highsTwo[index] << endl;
    }
    return 0;
}
