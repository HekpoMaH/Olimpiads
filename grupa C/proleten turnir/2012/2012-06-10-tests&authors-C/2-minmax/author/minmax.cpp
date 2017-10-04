#include<iostream>
using namespace std;

int main()
{
    int n;
    long long a[20], b[20], c, cmax, cmin;
    cin >> n >> c;
    cmax=c; cmin=c;
    for(int k=1; k<=n; k++)
      cin >> a[k];
    for(int k=1; k<=n; k++)
      cin >> b[k];
    for(int k=n; k>0; k--)
    {
        cmin = a[k]*(cmin-b[k]);
        cmax = a[k]*(cmax-b[k])+a[k]-1;
    }
    cout << cmin << " " << cmax << endl;
    return 0;
}
