///Task: decoding
///Author: Mladen Manev
#include<iostream>
#include<string>
using namespace std;

long long ans[100];

int main()
{
    string n;
    int len, kod1, kod2;
    cin >> n;
    len = n.size();
    ans[0] = 1; ans[1] = 1;
    for(int i=2; i<=len; i++)
    {
        kod1 = n[i-1]-'0';
        kod2 = (n[i-2]-'0')*10 + n[i-1]-'0';
        if (kod1 != 0) ans[i]+=ans[i-1];
        if (kod2 > 9 && kod2 < 27) ans[i]+=ans[i-2];
    }
    cout << ans[len] << endl;
    return 0;
}

