//varel
#include<iostream>
using namespace std;
int main()
{
    int v,k,n,br1=0,br2=0,dob=0,izv=0;
    char znak;
    cin>>v;
    cin>>k;
    cin>>n;
    for(int br=1;br<=n;br++)
    {
       cin>>znak; if(znak=='-') br1++;
                  if(znak=='+') br2++;
       cout<<endl;
       
    }
    
    for(int i=1;i<=n;i++)
    {
       dob=10*br2;
       izv=10*br1;
    }
    if(dob>izv) v=v+abs(dob-izv);
    if(izv>dob) v=v-abs(izv-dob);
    cout<<v<<endl;
    return 0;
}
       
    
