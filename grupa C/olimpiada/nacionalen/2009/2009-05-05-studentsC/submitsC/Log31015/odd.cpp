/*
TASK: odd
LANG: C++
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct cmp
{
       bool operator() (string a, string b)
       {
            long x=a.size();
            long y=b.size();
            if((x<y)||(x==y&&a<b)) return 1;
            else if((x>y)||(x==y&&a>=b)) return 0;
       }
};
long long i,n,br,e;
priority_queue<string,vector<string>,cmp> a;
string b,x,k;
int main()
{
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
             cin>>x;
             a.push(x);
    }
    for(i=1; i<=n; i++)
    {
             if(a.top()!=b) {if(br%2==1) {e=1; cout<<k<<endl; break;} br=1; b=a.top();}
             else {br++;}
             k=a.top();
             a.pop();
    }
    if(e==0) {cout<<a.top()<<endl;}
    //system ("pause");
    return 0;
}
