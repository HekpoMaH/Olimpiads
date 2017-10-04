#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int N;
    char a; int r=0;
    cin >> N;
    while(r<=N)
    {
        cin.get(a);
        if(a=='\n') r++;
        s.push_back(a);
    }
    bool flagw=false;
    int i0=0,brr=0,brzn=0,brd=0,ost=0,c=0,q;
    for(int i=1;i<s.size();i++)
    {
        if(brr==N-1) break;
        if(s[i]!='\n' && s[i]!=' ') { flagw=true; brzn++; }
        else if(s[i]==' ' && s[i+1]!=' ' && s[i+1]!='\n' && flagw) brd++;
        else if(s[i]=='\n') {
            ost=(60-brzn)%brd; c=(60-brzn)/brd;
            bool flag5=false,flag6=true;
            for(int j=i0;j<i;j++) 
            { 
             if(s[j]!=' ' && s[j]!='\n') { flag5=true; flag6=false; cout << s[j]; }
             else if(flag5 && !flag6) { 
                    if(ost>0) q=1; else q=0;
                    for(int h=0;h<c+q;h++) cout << " ";
                    ost--; flag6=true;
                }
            }
            cout << endl;
            i0=i+1; brr++; brzn=0; brd=0; flagw=false; } 
    }
    bool flag=false;
    for(int i=i0;i<s.size();i++)
    {
        if(s[i]==' ') { if(flag) cout << " "; flag=false; }
        else { flag=true; cout << s[i]; }
    }
    return 0;
}
