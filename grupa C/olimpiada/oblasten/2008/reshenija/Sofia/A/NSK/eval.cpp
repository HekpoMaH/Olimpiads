#include <iostream>
using namespace std;
long long fact(int i)
{
    if (i == 1) return 1;
    else return i * fact(i-1);
}
char a[32];
int cnt = 0;
int main()
{
    cin >> a;
    for (int i = 0; i <= strlen(a); i++) if (a[i] == '(') cnt++;
    if (cnt == 0) cnt = 1;
    cout << fact(cnt) << endl;
    //system("pause");
    return 0;
}
