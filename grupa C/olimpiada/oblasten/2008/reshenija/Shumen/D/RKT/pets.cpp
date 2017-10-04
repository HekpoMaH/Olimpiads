#include <iostream>
#include <cmath>
#include <string>
#include <string>
using namespace std;
int main()
{
    int a,n,brc=0,brg=0,i,j;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        a=s.size();
        for(j=0;j<a;j++)
        {
            if(s[j]=='C'||s[j]=='A'||s[j]=='T')
            brc++;
            else
            {
                if(s[j]=='G'||s[j]=='P'||s[j]=='I')
                brg++;
            }
        }
        if(brc==0&&brg==0)
        cout<<"UFO"<<endl;
        else
        {
            if(brc>brg)
            cout<<"CAT"<<endl;
            else
            {
                if(brc<brg)
                cout<<"GPI"<<endl;
                else
                cout<<"CAT-GPI"<<endl;
            }
        }
        brc=0;
        brg=0;
    }
    return 0;
}
