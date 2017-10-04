#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream fout("3lines.in");
    fout<<50000<<endl;
    for(int i=1;i<=50000;i++)
    {
        fout<<rand()<<" "<<rand()<<endl;
    }
    return 0;
}
