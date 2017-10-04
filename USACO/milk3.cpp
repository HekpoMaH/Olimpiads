/*
ID: dobrikg1
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
struct bucket
{
    int cap;
    int cmilk;
};
bucket a,b,c;
int used[20][20][20],usedc[20];
queue<bucket> qa,qb,qc;
bucket ca,cb,cc;
bucket na,nb,nc;
int st;
vector<int> ans;
int main()
{
    ifstream fin ("milk3.in");
    ofstream fout("milk3.out");
    fin>>a.cap>>b.cap>>c.cap;
    c.cmilk=c.cap;a.cmilk=b.cmilk=0;
    qa.push(a);qb.push(b);qc.push(c);
    int cnr=0;
    while(!qa.empty())
    {
        ca=qa.front();
        cb=qb.front();
        cc=qc.front();if(ca.cmilk==0){cout<<"cc="<<cc.cmilk<<endl;usedc[cc.cmilk]=1;}
        
        //cout<<ca.cmilk<<" "<<cb.cmilk<<" "<<cc.cmilk<<endl;
        qa.pop();qb.pop();qc.pop();
        cnr++;
        used[ca.cmilk][cb.cmilk][cc.cmilk]=1;
        if(ca.cmilk>0&&cb.cap-cb.cmilk>0)
        {
            st=min(cb.cap-cb.cmilk,ca.cmilk);
            ca.cmilk-=st;cb.cmilk+=st;
            if(used[ca.cmilk][cb.cmilk][cc.cmilk]==0){qa.push(ca);qb.push(cb);qc.push(cc);}
            ca.cmilk+=st;cb.cmilk-=st;
        }
        if(ca.cmilk>0&&cc.cap-cc.cmilk>0)
        {
            st=min(cc.cap-cc.cmilk,ca.cmilk);
            ca.cmilk-=st;cc.cmilk+=st;
            if(used[ca.cmilk][cb.cmilk][cc.cmilk]==0){qa.push(ca);qb.push(cb);qc.push(cc);}ca.cmilk+=st;cc.cmilk-=st;
        }
        if(cb.cmilk>0&&ca.cap-ca.cmilk>0)
        {
            st=min(ca.cap-ca.cmilk,cb.cmilk);
            cb.cmilk-=st;ca.cmilk+=st;
            if(used[ca.cmilk][cb.cmilk][cc.cmilk]==0){qa.push(ca);qb.push(cb);qc.push(cc);}cb.cmilk+=st;ca.cmilk-=st;
        }
        if(cb.cmilk>0&&cc.cap-cc.cmilk>0)
        {
            st=min(cc.cap-cc.cmilk,cb.cmilk);
            cb.cmilk-=st;cc.cmilk+=st;
            if(used[ca.cmilk][cb.cmilk][cc.cmilk]==0){qa.push(ca);qb.push(cb);qc.push(cc);}cb.cmilk+=st;cc.cmilk-=st;
        }
        if(cc.cmilk>0&&ca.cap-ca.cmilk>0)
        {
            st=min(ca.cap-ca.cmilk,cc.cmilk);
            cc.cmilk-=st;ca.cmilk+=st;
            if(used[ca.cmilk][cb.cmilk][cc.cmilk]==0){qa.push(ca);qb.push(cb);qc.push(cc);}cc.cmilk+=st;ca.cmilk-=st;
        }
        if(cc.cmilk>0&&cb.cap-cb.cmilk>0)
        {
            st=min(cb.cap-cb.cmilk,cc.cmilk);
            cc.cmilk-=st;cb.cmilk+=st;
            if(used[ca.cmilk][cb.cmilk][cc.cmilk]==0){qa.push(ca);qb.push(cb);qc.push(cc);}cc.cmilk+=st;cb.cmilk-=st;
        }
    }
    int cnt=0;
    cout<<usedc[0]<<endl;
    for(int i=0;i<=20;i++)if(usedc[i]==1){ans.push_back(i);cnt++;}
    for(int i=0;i<cnt-1;i++)fout<<ans[i]<<" ";
    fout<<ans[cnt-1];
    fout<<endl;
    return 0;    
}