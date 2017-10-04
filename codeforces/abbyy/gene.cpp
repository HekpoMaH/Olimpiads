#include<fstream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using  namespace std;
int n,k;
long long a[300009],ps[300009],mx=-1000000000000000000LL,mn,mn2,s;
map<int,int> used;
vector<int> ans,c;
int main()
{
    srand(time(NULL));
    ofstream fout("test.in");
    fout<<1000<<endl;
    for(int i=1;i<=1000;i++)
    {
        k=rand()%60;
        if(rand()%2==1)fout<<(long long)k<<" ";else fout<<-k<<" ";
    }
    fout<<endl;
}


