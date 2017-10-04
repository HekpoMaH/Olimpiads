#include<iostream>
using namespace std;
long long n,m,a;
int main()
{
    cin>>n>>m>>a;
    if(n%a!=0){n/=a;n++;}
    else n/=a;
    if(m%a!=0)m/=a,m++;
    else m/=a;
    cout<<m*n<<endl;
    return 0;
}