#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;
int n,br;
bool aa[100000000];
int main()
{
    cin>>n;
    for(int i=1;i<=10000;i++)aa[i*i]=true;
    //cout<<aa[10000*10000]<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((int)sqrt(i*i+j*j)==sqrt(i*i+j*j)&&(int)sqrt(i*i+j*j)<=n) br++;
            //cout<<i<<" "<<j<<" "<<i*i+j*j<<" "<<aa[i*i+j*j]<<" "<<br<<endl;}
        }
    }
    cout<<br-1<<endl;
}
