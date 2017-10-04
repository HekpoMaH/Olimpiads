#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    ofstream fout("wateringg.in");
    fout<<100<<" "<<1000000000<<" "<<342445593<<endl;
    srand(time(NULL));
    for(int i=1;i<=100;i++)
    {
        fout<<rand()*30000+rand()<<" ";
    }
    fout<<endl;
    return 0;
}