/*
ID: dobrikg1
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
int s,n,br,br2;
bool check(int k,int sys)
{
    string s,r;
    while(k>=sys)
    {
        s+='0'+k%sys;
        k/=sys;
    }
    if(k!=0)s+='0'+k;
    r=s;
    reverse(s.begin(),s.end());
    if(r==s)return true;
    return false;
}
int main()
{
    ifstream fin ("dualpal.in");
    ofstream fout("dualpal.out");
    fin>>n>>s;
    int i=s+1;
    //cout<<check(13,3)<<endl;;
    while(br<n)
    {
        br2=0;
        if(check(i,2))br2++;
        if(check(i,3))br2++;
        if(check(i,4))br2++;
        if(check(i,5))br2++;
        if(check(i,6))br2++;
        if(check(i,7))br2++;
        if(check(i,8))br2++;
        if(check(i,9))br2++;
        if(check(i,10))br2++;
        if(br2>=2){fout<<i<<endl;br++;}
        i++;
    }
    return 0;
}
