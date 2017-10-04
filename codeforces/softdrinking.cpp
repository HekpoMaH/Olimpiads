#include<iostream>
using namespace std;
int n,k,l,c,d,p,nl,np,ml;
int main()
{
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    ml=k*l;
    d*=c;
    int mn=min(d,min(ml/nl,p/np));
    cout<<mn/n<<endl;
    return 0;
}
