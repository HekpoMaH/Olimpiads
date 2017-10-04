#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
long long n,div=2;
vector<int> ans;
int main()
{
    ifstream fin("proddiff.in");
    ofstream fout("proddiff.out");
    fin>>n;ans.push_back(1);
    //cin>>n;

    while(div*div<=n)
    {//cout<<div<<" "<<n<<endl;
        if(n%div==0)
        {
            ans.push_back(div);
            if(div!=n/div)ans.push_back(n/div);n/=div;//cout<<div<<endl;
        }
        div++;
    }
    fout<<ans.size()<<endl;

    for(int i=0;i<ans.size()-1;i++)fout<<ans[i]<<" ";
    fout<<ans[ans.size()-1]<<endl;
}

