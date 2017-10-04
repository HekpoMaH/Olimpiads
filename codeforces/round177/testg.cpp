#include<fstream>
using namespace std;
int main()
{
    ofstream fout("testtt.in");
    fout<<100<<" "<<100<<" "<<1<<endl;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            fout<<(i-1)*100+j<<" ";
        }fout<<endl;
    }
}
