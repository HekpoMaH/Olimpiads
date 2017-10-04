#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXS 1000000
#define INF 999999999

int N, S, dyn[MAXS+1];

int main()
{
    cin >> S >> N;

    int i;
    for(i = 1;i < N+1;i++)
        dyn[i] = 1;

    int j;
    for(;i <= S;i++)
    {
        dyn[i] = dyn[i-1];
        for(j = N; j >= 2;j--)
        {
            if(dyn[i] > dyn[i-j])
                dyn[i] = dyn[i-j];

            if(i % j == 0)
                if(dyn[i] > dyn[i/j])
                    dyn[i] = dyn[i/j];
        }
        dyn[i]++;
        //cout << i << " " << dyn[i] << endl;
    }

    cout << dyn[S] << endl;

    return 0;
}
