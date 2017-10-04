#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double a,s=0;
    int br=0;
    for(int i=1;i<=n;i++)
    {
            br++;
            cin>>a;
            s=s+a;
    }
    double sr;
    sr=s/br;
    cout<<sr<<endl;
    system("pause");
    return 0;
}
