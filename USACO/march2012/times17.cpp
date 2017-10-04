#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
int model[6]={1,0,0,0,1};
string g;
int given[1000];
int result[10000];
int main()
{
    ifstream fin("times17.in");
    ofstream fout("times17.out");
    fin>>g;
    int n=g.size();
    for(int i=0;i<n;i++)given[i]=g[i]-'0';
    reverse(given,given+n);
    for(int i=0;i<n;i++)
    {
        result[i]+=given[i];
        result[i+4]+=given[i];
    }
    for(int i=0;i<n+4;i++)if(result[i]>1){result[i+1]+=result[i]/2;result[i]%=2;}
    if(result[n+4]==1)n++;
    reverse(result,result+(n+4));
    for(int i=0;i<n+4;i++)fout<<result[i];
    fout<<endl;
    return 0;
}
