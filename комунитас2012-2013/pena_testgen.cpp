#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int a,m,n;
int main()
{
    srand(time(NULL));
    ofstream fout("pena_ult.in");
    m=100;n=100;
    fout<<m<<" "<<n<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            a=rand()%100;
            fout<<100<<" ";
        }
        a=rand()%100;
        fout<<100;
        fout<<endl;
    }
    a=rand()%100;
    fout<<a<<endl;
    int x;
    for(int i=1;i<=a;i++)
    {
        x=rand()%10000;
        fout<<x<<" ";
        x=rand()%10000;
        fout<<x<<endl;
    }
}