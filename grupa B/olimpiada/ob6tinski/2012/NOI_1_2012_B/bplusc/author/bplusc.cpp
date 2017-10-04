/// Task: bplusc
/// Author: Mladen Manev

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string a, b, c, s;
    int n, pos, prenos, x;
    cin >> a;
    n = a.size();
    sort(&a[0],&a[0]+n);
    b = a;
    pos = 0;
    while (b[pos] == '0')
        pos++;
    if (pos != 0) swap(b[pos], b[0]);
    c = "";
    for(int i=0; i<n; i++)
        c = a[i] + c;
    s = "";
    prenos = 0;
    for(int i=n-1; i>=0; i--)
    {
        x = b[i]  + c[i] - 2*'0' + prenos;
        if (x > 9)
        {
            prenos = 1;
            x = x - 10;
        }
        else
            prenos = 0;
        s = char(x+'0') + s;
    }
    if (prenos == 1) 
        s = '1' + s;
    cout << s << endl;
   // cout << a << endl << b << endl << c << endl << s << endl;
    return 0;
    
}