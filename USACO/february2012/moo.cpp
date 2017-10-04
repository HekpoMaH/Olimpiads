#include<iostream>
#include<string>
#include<fstream>
using namespace std;
long long n;
string tek="moo",o="ooo";
int main()
{
    ifstream fin("moo.in");
    ofstream fout("moo.out");
    cin>>n;
    while(tek.size()<=n)
    {
        tek=tek+"m"+o+tek;
        o+="o";
        //pr=tek;
    }
    //cout<<tek<<endl;
    fout<<tek[n-1]<<endl;
    return 0;
}
