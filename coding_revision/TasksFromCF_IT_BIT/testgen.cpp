#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,q;
int main()
{
    n=200000;q=200000;

    srand(time(NULL));
    ofstream fout("test.in");fout<<n<<" "<<q<<endl;
    for(int i=1;i<=n;i++)
    {
        fout<<rand()%200000+1<<" ";
    }
    fout<<endl;
    for(int i=1;i<=q;i++)
    {
        int k=0;
        int p=rand()%200000+1;
        fout<<p<<" ";while(k<p)k=rand()%200000+1;fout<<k<<endl;
    }
}
