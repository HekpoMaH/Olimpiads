#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
int n;
int a[600009];
vector<int> used[5555];
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>n;
    for(int i=1;i<=2*n;i++)fin>>a[i],used[a[i]].push_back(i);
    for(int i=0;i<=5000;i++)if(used[i].size()%2!=0){fout<<-1<<endl;return 0;}
    for(int i=0;i<=5000;i++)
    {
        if(used[i].size()!=0)
        {
            for(int j=0;j<used[i].size();j+=2)fout<<used[i][j]<<" "<<used[i][j+1]<<endl;
        }
    }
}
