/*
ID: dobrikg1
PROG: ride
LANG: C++
*/
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
string ufo,group;
long long pr1=1,pr2=1,n,m;
int main()
{
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    fin>>ufo>>group;
    //fin>>group;
    //cout<<ufo<<endl;
    n=ufo.size();
    m=group.size();
    
    for(int i=0;i<n;i++)pr1*=ufo[i]-'A'+1;
    for(int i=0;i<m;i++)pr2*=group[i]-'A'+1;
    //cout<<pr1<<" "<<pr2<<endl;
    if(pr1%47==pr2%47){fout<<"GO"<<endl;return 0;}
    fout<<"STAY"<<endl;
    return 0;
}
