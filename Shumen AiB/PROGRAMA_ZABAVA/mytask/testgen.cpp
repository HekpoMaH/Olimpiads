#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<vector>
#include <stdlib.h>
using namespace std;
vector<int> rows[102];
int br;
int main()
{
    ifstream ifile;
    ifile.open  ("TestNumbers.txt");
    string s;
    ofstream ofile;
    srand (time(NULL));
    while (ifile >>s)
    {
        br++;

        int n=0;
        ofile.open (("honey."+s+".in").c_str());
        if(br==26)n=100;
        else if(br>6)while(n==0||n<=80)n=rand()%101;
        else while(n==0||n>=11)n=rand()%101;
        int m=0;int sr=0;int el=0;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            rows[i].clear();
            sr=0;
            if(br>6)while(sr==0||sr<=60)sr=rand()%101;
            else while(sr==0||sr>=9)sr=rand()%101;
            sum+=sr;
            rows[i].push_back(sr);
            for(int j=1;j<=sr;j++)
            {
                el=0;
                while(el==0)el=rand()%100;
                rows[i].push_back(el);
            }
        }
        while(m>sum||m==0)m=rand()%10001;
        ofile<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<rows[i].size();j++)ofile<<rows[i][j]<<" ";
            ofile<<endl;
        }
        ofile.close();
    }
    ifile.close();
    return 0;
}
