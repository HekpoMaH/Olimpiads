#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cin>>n;
    long long S = 0;
    for (int i = 1;i<=n; i++)
    {
        cin>>a;
        S = S + a ;
    }
    cout << S <<endl;
    return 0;
}