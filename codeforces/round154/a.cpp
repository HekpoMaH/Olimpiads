#include<fstream>
#include<string>
using namespace std;
int b,g;
string s1,s2;
int br1,br2;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>b>>g;
    int b1=b,g1=g;
    while(b1!=0||g1!=0||b!=0||g!=0)
    {
        if(b1>0)s1+='B',b1--;
        if(g1>0)s1+='G',g1--;
        if(g>0)s2+='G',g--;
        if(b>0)s2+='B',b--;
    }
    for(int i=0;i<s1.size()-1;i++)if(s1[i]!=s1[i+1])br1++;
    for(int i=0;i<s2.size()-1;i++)if(s2[i]!=s2[i+1])br2++;
    if(br1>br2)fout<<s1<<endl;
    else fout<<s2<<endl;
}
