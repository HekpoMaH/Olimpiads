#include<iostream>
#include<string>
using namespace std;
string w;
int br,pkmp[250005],pos1,pos2=2,sw;
int main()
{
    getline(cin,w);
    sw=w.size();
    while(pos2<=sw)
    {
        if(w[pos1]==w[pos2-1])
        {
            pkmp[pos2]=pos1+1;
            pos2++;pos1++;
        }
        else
        {
            if(pos1>0)pos1=pkmp[pos1];
            else pos2++;
        }
    }
    //for(int i=0;i<=sw;i++)
    //cout<<pkmp[i]<<" ";
    //cout<<endl;
    cout<<sw-pkmp[sw]<<endl;
    return 0;
}