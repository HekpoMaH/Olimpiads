#include<iostream>
using namespace std;
int len(int k)
{
    int x;
    if(k==-1) return 0; 
    x=len(k-1);
    return x+k+3+x;
}
char solve(int n,int k)
{
    if(n>len(k))return solve(n,k+1);
    if(n<=len(k-1))return solve(n,k-1);
    n-=len(k-1);
    if(n<=k+3)
    {
        if(n==1)return 'm';
        else return 'o';
    }
    n-=k+3;
    return solve(n,k-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n,0)<<endl;
    return 0;
}