#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a,b;
    int k, n, p, br = 0;
    cin >> k >> a >> b;
    n = a.size();
    for(int i=0; i < n-k+1; i++)
    { p = (9 + b[i] - a[i])%9;
      br += p;
      for(int j=0; j<k; j++)
        a[i+j] = '1' + (a[i+j]-'1'+p)%9;
    }
    if (a == b) cout << br << endl;
    else cout << 0 << endl;
    return 0; 
}
