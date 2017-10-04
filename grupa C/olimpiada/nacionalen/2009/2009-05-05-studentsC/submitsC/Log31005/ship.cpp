/*
TASK:SHIP
LANG:C++
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t[100001], p[100001];
    for(int i=0; i<n; i++) cin >> t[i];
    for(int i=0; i<n; i++) cin >> p[i];
    int k=n, b[100001], j=0;
    for(int i=0; i<n; i++){
            if(p[i]==i){ k--; continue;}
            b[j]=t[i];
            j++;
    }
    sort(b, b+k);
    int sum=0;
    for(int i=0; i<k; i++)
    {
            sum+=b[i];
    }
    int v=k/3;
    if(k%3!=0)
       for(int i=0; i<v; i++){ sum+=2*b[i];}
    else for(int i=0; i<v; i++){ sum+=b[i];}
    cout << sum << endl;
    return 0;
}
