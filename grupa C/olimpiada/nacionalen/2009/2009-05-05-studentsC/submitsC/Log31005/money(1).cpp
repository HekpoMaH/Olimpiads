/*
TASK:MONEY
LANG:C++
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[200001];
    for(int i=0; i<n; i++)
    {
            cin >> x[i];
    }
    sort(x,x+n);
    int j=0;
    bool ok=false;
    while(ok==false)
    {
                     for(int i=n-1; i>=j+1; i--)
                     {
                             if(x[j]+x[i]<=x[n-1]){ok=false; if(i>(j+(n-1))/2){ n--; break;}
                                                   else {j++; break;}}
                             else ok=true;
                     } 
    }
    if(n-j<=2) cout << 1 << endl;
    else 
    cout << n-j << endl;
    return 0;
}
