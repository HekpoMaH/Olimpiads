#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int n;
const int M=1000000;
int main()
{
    cin>>n;
     long long cnt = ((n%6+ n)/2%M * ((1+ n/6)%M));
     if(n%6==0) cnt++;
cout << cnt%M << endl;
}
