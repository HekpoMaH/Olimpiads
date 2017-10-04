#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream fout("cowrow.in");
    fout<<1000<<endl;
    for(int i=1;i<=1000;i++)
    {
        fout<<rand()%1000000<<endl;
    }
    return 0;
}