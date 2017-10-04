//VALID
#include <iostream>
using namespace std;
int main()
{
    int dd,mm,gggg;
    cin>>dd>>mm>>gggg;
    if(dd<=31&&mm<=12&&mm!=2) {cout<<"Yes"<<endl;
                               dd++;
                               cout<<dd<<'.'<<" "<<mm<<'.'<<" "<<gggg<<'.'<<endl;}
    if (dd<=29&&mm==2) {cout<<"Yes"<<endl;
                        dd++;
                        cout<<dd<<'.'<<" "<<mm<<'.'<<" "<<gggg<<'.'<<endl;}
    if(dd>29&&mm==2) {cout<<"No"<<endl;
                      cout<<29<<endl;}
    
    return 0;
}
                               
    
