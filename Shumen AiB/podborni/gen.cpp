#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout("pravoyg.in");
    fout<<100<<" "<<100<<endl;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)fout<<"H";
        fout<<endl;
    }
}
