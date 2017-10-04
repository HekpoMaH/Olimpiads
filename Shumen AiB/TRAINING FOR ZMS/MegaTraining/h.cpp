#include<iostream>
#include <vector>
#include<cstdio>
using namespace std;
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
vector<int> find_lis(vector<int> &a)
{
 vector<int> b, p(a.size());
int u, v;
if (a.size() < 1) return b;
 b.push_back(0);
for (size_t i = 1; i < a.size(); i++) {
if (a[b.back()] < a[i]) {
 p[i] = b.back();
 b.push_back(i);
continue;
}
for (u = 0, v = b.size()-1; u < v;) {
int c = (u + v) / 2;
if (a[b[c]] < a[i]) u=c+1; else v=c;
}
if (a[i] < a[b[u]]) {
if (u > 0) p[i] = b[u-1];
 b[u] = i;
}
}
for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
return b;
}
void main1()
{
int n1;
cin>>n1;int a[n1];
for(int i=0;i<n1;i++)
{
    cin>>a[i];
}
 vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
 vector<int> lis = find_lis(seq);
cout<<lis.size()<<endl;

}
int main()
{
    int t=1;
    cin>>t;
    //t=1;
    while(t--)
    {
        main1();
    }
}
