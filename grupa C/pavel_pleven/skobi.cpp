#include<iostream>
#include<string>
#include<vector>
using namespace std;
string a;
vector<int> ans;
int brl,brd,bri,brk;
int main()
{
    cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]=='(')brl++;
        if(a[i]==')')brd++;
        if(a[i]==']')brk++;
        if(i==n-1||(a[i]==')'&&a[i+1]=='('))//ako ima takiva skobi ili niza e svyr6il- proverqvame
        {
            if(brk==0)//ako nqma ]
            {
                if(brl-brd<0){cout<<0<<endl;return 0;}//ako desnite sa pove4e ot levite- N.R.
                if(brl>=brd){brl-=brd;brd=0;}//ako ne sa gi izravnqvame
            }
            if(brk>1){cout<<0<<endl;return 0;}//izli6ni skobi
            if(brk==1)
            {
                if(brl-brd>0)ans.push_back(brl-brd);//tolkova 6te dopylvame
                if(brl-brd<=0){cout<<0<<endl;return 0;}//ako razlikata m/u br levi i br desni e otricatelen- N.R.
                //a ako e raven na nula to ] e izli6na
                brl=0;brd=0;brk=0;
            }
        }
    }
    //izhod ako ima r-nie
    //pravq go taka za6toto ako ima nekorektnost sled kato sam izvel ne6to 6te stane 1 0, koeto e gre6no
    for(auto q: ans)cout<<q<<" ";
    cout<<endl;
    return 0;
}
/*
input:
(((]))(((]
output:
1 3
input:
((])((]))))
output:
0
input:
((((]))]
output:
0
*/