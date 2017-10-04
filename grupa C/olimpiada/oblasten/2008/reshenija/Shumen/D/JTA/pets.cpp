#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s;
    int l,i,br=0,brn=0,brk=0,brs=0,sz;
    cin>>l;
    do
    {
        cin>>s;
        br++;
        sz=s.size();
        for(i=0;i<sz;i++)
        {
            if(s[i]=='C'||s[i]=='A'||s[i]=='T') brk++;
            else
            if(s[i]=='G'||s[i]=='P'||s[i]=='I') brs++;
            
            
        }
    if(brk>brs) cout<<"CAT"<<endl;
    if(brk<brs) cout<<"GPI"<<endl;
    if(brk==brs&&brk!=0&&brs!=0) cout<<"CAT-GPI"<<endl;
    if(brk==0&&brs==0) cout<<"UFO"<<endl;
    } 
    while(br<l);
    return 0;
}
