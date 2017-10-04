#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream fout("metro.out");
    fout<<2500<<" "<<2500<<" "<<2000<<endl;
    for(int i=1;i<=2000;i++)
    {
        fout<<rand()%2500<<" "<<rand()%2500<<endl;
    }
    return 0;
}
