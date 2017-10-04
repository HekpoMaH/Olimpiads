///Task: Balance
///Author: Mladen Manev

#include<iostream>
#include<algorithm>
using namespace std;

int a[10], n, ans = 0, lpan, rpan;

void set(int num)
{
    if(num == n)
    {
        ans++;
        return;
    }
    if (lpan + a[num] <= rpan)
    {
        lpan += a[num];
        set(num + 1);
        lpan -= a[num];
    }
    rpan += a[num];
    set(num + 1);
    rpan -= a[num];
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> a[i];
    sort(a, a+n);
    do
    {
        lpan=0; rpan=0;
        set(0);

    }while(next_permutation(a,a+n));
    cout << ans << endl;
    return 0;
}
