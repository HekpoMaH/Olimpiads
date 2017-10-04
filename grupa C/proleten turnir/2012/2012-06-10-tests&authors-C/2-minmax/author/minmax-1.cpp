#include<iostream>
using namespace std;

int main()
{
    int n;
    long long a[20], b[20], cmin, p=1;
    cin >> n >> cmin;
    for(int k=1; k<=n; k++)
      cin >> a[k];
    for(int k=1; k<=n; k++)
      cin >> b[k];
    for(int k=n; k>0; k--)
    {
        cmin = a[k]*(cmin-b[k]);
        p*=a[k];
    }
    cout << cmin << " " << cmin + p - 1 << endl;
    return 0;
}
