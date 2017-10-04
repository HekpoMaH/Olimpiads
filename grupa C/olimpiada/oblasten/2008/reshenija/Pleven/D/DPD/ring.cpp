#include<iostream>
#include<vector>
using namespace std;
long a,b,c,d,e,f,i,j,n,k;
vector<long> z,y;
int main()
{
    cin>>n>>e;
    for(i=1; i<=n; i++)
    {
             cin>>k;
             z.push_back(k);
             y.push_back(i);
    }
    c=e;
    for(i=0; i<=n-1; i++)
    {
             d=c%n-1+n-d;
             if(d>=n) {d=d-n;}
             c=z[d];
             z.erase(z.begin()+d);
             y.erase(y.begin()+d);
             n--;
    }
    cout<<y[0]<<endl;
    return 0;
}
