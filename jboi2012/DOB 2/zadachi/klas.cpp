#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int n,oc;
    double s;
    cin>>n;
    s=0;
    for(int br=1;br<=n;br++)
    {
            cin>>oc;
            s=s+oc;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<s/n<<endl;
    system("pause");
    return 0;
}
