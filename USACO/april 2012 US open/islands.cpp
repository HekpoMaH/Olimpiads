#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long h[100000];
long long n;
void solveislands()
{
    ofstream fout("islands.out");
    long long last=-1,br=0,ibr=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i]==last)
        {
            br++;
        }
        else{br=1;ibr++;}
        last=h[i];
        //cout<<br<<" "<<h[i]<<endl;
    }
    fout<<ibr-1<<endl;
}
int main()
{
    ifstream fin("islands.in");
    ofstream fout("islands.out");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>h[i];
    }
    sort(h+1,h+n+1);
    for(int i=1;i<=n;i++)
    {
        fout<<h[i]<<" ";
    }
    fout<<endl;
    solveislands();
    return 0;
}