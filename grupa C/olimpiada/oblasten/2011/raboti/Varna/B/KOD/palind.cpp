#include <iostream>
#include <queue>
using namespace std;

#define MAXN 10001

int N, pal[MAXN], ans = 0;
queue <int> sol;

bool ispal(int start, int end)
{
    //cout << "pp " << start << " " << end << endl;
    while(start < end)
    {
        //cout << "tt " << pal[start] << " " << pal[end] << " " << start << " " << end << endl;
        if(pal[start] != pal[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main()
{
    cin >> N;

    int i;
    for(i = 0;i < N;i++)
        scanf("%d", &pal[i]);

    int j;
    for(i = 0;i < N;i++)
    {
        for(j = N-1;j >= i;j--)
        {
            //cout << i << " and " << j << "?" << endl;
            if(ispal(i, j))
            {
                //cout << i << " and " << j << "!" << endl;
                i = j;
                ans++;
                sol.push(j+1);
                break;
            }
        }
    }

    cout << ans << endl;
    if(sol.size() != 1)
    {
        cout << sol.front();
        sol.pop();
        while(sol.size() != 1)
        {
            cout << " " << sol.front();
            sol.pop();
        }
        cout << endl;
    }
}
