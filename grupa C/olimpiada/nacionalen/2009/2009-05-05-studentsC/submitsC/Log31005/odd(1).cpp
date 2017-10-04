/*
TASK:ODD
LANG:C++
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    long long *b=new long long[1000001];
    for(int i=0; i<n; i++)
    {
            cin >> b[i];
    }
    sort(b,b+n);
    int br=1;
    for(int i=1; i<n; i++)
    {
            if(b[i]==b[i-1]) br++;
            else {
                 if(br%2==1) { cout << b[i-1] << endl; break;}
                 br=1;
                 }
            if(i==n-1){  if(br%2==1) { cout << b[i] << endl; break;}}
    }
    return 0;
}
