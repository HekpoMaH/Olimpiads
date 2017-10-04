#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
long long n;
string s;
int main()
{
    cin>>n;
    if(n>=0)
    {
        cout<<n<<endl;
        return 0;
    }
    if(n%10<=n/10%10)cout<<n/10<<endl;
    else
    {
        cout<<(n/100)*10+n%10<<endl;
    }
}


