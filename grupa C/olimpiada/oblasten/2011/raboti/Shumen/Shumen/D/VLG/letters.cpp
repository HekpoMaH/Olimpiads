#include <iostream>
using namespace std;
int main()
{
    int n,i,br1=0,br2=0,br3=0,br4=0,br=0,n2,n3,n4,h;
    char c,e;
    string s1,s2,s3,s4;
    cin>>n>>c;
    cin.get(e);
    for(i=0;i<n;i++)
    {
        cin>>s1>>s2>>s3>>s4;
        n2=s2.size();
        n3=s3.size();
        n4=s4.size();
        if(s1[0]<='Z')s1[0]+='a'-'A';
        if(s1[0]==c)br1++;
        for(h=0;h<n2;h++)
        {
            if(s2[h]<='Z')s2[h]+='a'-'A';
            if(s2[h]==c){br2++;break;}
        }
        for(h=0;h<n3;h++)
        {
            if(s3[h]<='Z')s3[h]+='a'-'A';
            if(s3[h]==c)br++;
        }
        if(br>=2)br3++;
        br=0;
        if(s4[n4-1]<='Z')s4[n4-1]+='a'-'A';
        if(s4[n4-1]==c)br4++;
        cin.get(e);
    }
    cout<<br1<<' '<<br2<<' '<<br3<<' '<<br4<<endl;
    return 0;
}
