#include <iostream>
#define MAXN 512
#define MAX (unsigned)-1
using namespace std;
int n, p;
double nums[MAXN];
double mini = MAX;
double cache[MAXN][MAXN];
double calc(int from, int to)
{
    double d1 = 0;
    if (cache[from][to]) d1 = cache[from][to];
    else
    {
        double sum = 0;
        double resc = 0;
        for (int i = from; i <= to; i++) sum += nums[i];
        sum /= (to - from + 1);
        for (int i = from; i <= to; i++) d1 += (sum - nums[i]) * (sum - nums[i]);
        cache[from][to] = d1;
    }
    return d1;
}
void bt (int group, int from, int to, double res)
{
    //cout << "bt(" << group << ", " << from << ", " << to << ", " << res << ")" << endl;
    if (res >= mini) return;
    if (group > p) return;
    if (group == p && to != n) return;
    if (to >= n && group < p) return;
    //cout << "bt(" << group << ", " << from << ", " << to << ", " << res << ")" << endl << endl;
    double d1 = 0;
    if (from != to) d1 = calc(from, to);
    d1 += res;
    if (to == n) { if (d1 < mini) mini = d1; return; }
    for (int i = 1; i <= n - to; i++) bt(group+1, to+1, to+i, d1);
}
int main()
{
    int i;
    cin >> n >> p;
    for (i = 1; i <= n; i++) cin >> nums[i];
    // optimization?
    int test = p;
    double res = 0;
    for (i = 1; i <= p; i += 2)
    {
        if (test == 1) break;
        res += calc(i, i+1);
        test--;
    }
    res += calc(i, n);
    mini = res;
    //cout << mini << endl;
    for (int i = 1; i <= 2; i++) bt (1, 1, i, 0);
    //cout << mini << endl;
    mini *= 10000;
    mini = (int)mini;
    mini = mini / 10000;
    if ((int)mini == mini) cout << mini << ".0" << endl;
    else cout << mini << endl;
    //system("pause");
    return 0;
}
