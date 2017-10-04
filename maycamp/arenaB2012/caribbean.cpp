#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> v;
int br;
bool check(vector<int> s)
{
    int ost1,ost2;
    ost1=1;
    for(int i=0;i<s.size();i++)
    {
        ost2=v[i]/n;
        if(v[i]%n!=0)ost2++;
        if(ost2==ost1)return false;
        ost1=ost2;
    }
    if(ost2==1)return false;
    return true;
}
int main()
{
    cin>>n;
    for(int i=2;i<=3*n;i++)v.push_back(i);
    do
    {
        if(check(v)){br++;br%=1000003;}
    }while(next_permutation(v.begin(),v.end()));
    cout<<br<<endl;
    return 0;
}