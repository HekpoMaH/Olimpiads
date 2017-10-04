#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using  namespace std;
int n,br;
void checsub(int &x)
{
    int k=x,mx=0;
    while(k!=0)mx=max(mx,k%10),k/=10;
    x-=mx;
}
int main()
{
    cin>>n;
    while(n!=0)checsub(n),br++;
    cout<<br<<endl;
}

