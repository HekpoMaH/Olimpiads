#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[100009];
int used[10004],sum[10004],mn=100009;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>n;
    for(int i=1;i<=n;i++)fin>>a[i],used[a[i]]++;
    for(int i=1;i<=10000;i++)sum[i]=sum[i-1]+used[i];
    sort(a+1,a+n+1);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int x=n-(sum[2*a[i]]-sum[a[i-1]]);mn=min(x,mn);
        //cout<<a[i]<<" "<<x<<" "<<sum[2*a[i]]<<" "<<sum[a[i-1]]<<endl;
    }
    fout<<mn<<endl;
}
