#include<fstream>
#include<iostream>
//#include<algorithm>
using namespace std;
int n,l;
int a[100],rope[10000],br;
bool check(int i)
{
    int k=1;
    while(i-k>=1&&i+k<n){if(rope[i-k]!=rope[i+k])break;k++;}//cout<<i-k<<" "<<i+k<<endl;
    if(i-k==0||i+k==n)return true;
    return false;
    //return 1;
}
int main()
{
    ifstream fin("folding.in");
    ofstream fout("folding.out");
    cin>>n>>l;
    for(int i=0;i<n;i++){cin>>a[i];rope[a[i]]=1;}
    //sort(a,a+n);
    for(int i=1;i<=l;i++)
    {
        //cout<<check(i)<<endl;
        if(check(i)==true)br++;
        //cout<<"br="<<br<<" ";
        //cout<<i<<endl;
    }
    cout<<br<<endl;
    return 0;
}
