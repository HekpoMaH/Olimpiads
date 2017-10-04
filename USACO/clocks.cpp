/*
ID: dobrikg1
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int moves[1000],bs=9999,ts;
struct movement
{
    int x[11];
};
movement k[9];
struct clocks
{
    int pos[11];
    queue<int> mov;
};
clocks a;
queue<clocks> q;
bool check(clocks x)
{
    //for(int i=0;i<9;i++)cout<<a[i]<<" ";
    //cout<<endl;
    for(int i=0;i<9;i++)if(x.pos[i]%12!=0)return false;
    return true;
}
void dfs(int a[11],int depth)
{    
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    //cout<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;
    //cout<<a[6]<<" "<<a[7]<<" "<<a[9]<<endl;
    if(check(a)==true)
    {
        //cout<<check(a)<<endl;
        //for(int i=0;i<ts;i++)cout<<moves[i]<<" ";
        //cout<<endl;
        bs=ts;
        for(int i=0;i<ts;i++){bmoves[i]=moves[i];}
    }
    if(depth==0)return;
    for(int i=0;i<9;i++)
    {
        //cout<<"i="<<i<<endl;
        for(int j=0;j<9;j++){a[j]+=3*k[i].x[j];}
        moves[ts]=i;ts++;
        dfs(a,depth-1);
        ts--;
        moves[ts]=0;
        for(int j=0;j<9;j++){a[j]-=3*k[i].x[j];}
    }
}
int main()
{
    ifstream fin ("clocks.in");
    ofstream fout("clocks.out");
    fin>>x.a[0]>>x.a[1]>>x.a[2];//ABC
    fin>>x.a[3]>>x.a[4]>>x.a[5];//DEF
    fin>>x.a[6]>>x.a[7]>>x.a[8];//GHI
    //move 1
    k[0].x[0]=1;k[0].x[1]=1;k[0].x[3]=1;k[0].x[4]=1;
    //move 2
    k[1].x[0]=1;k[1].x[1]=1;k[1].x[2]=1;
    //move 3
    k[2].x[1]=1;k[2].x[2]=1;k[2].x[4]=1;k[2].x[5]=1;
    //move 4
    k[3].x[0]=1;k[3].x[3]=1;k[3].x[6]=1;
    //move 5
    k[4].x[1]=1;k[4].x[3]=1;k[4].x[4]=1;k[4].x[5]=1;k[4].x[7]=1;
    //move 6cfi
    k[5].x[2]=1;k[5].x[5]=1;k[5].x[8]=1;
    //move 7degh
    k[6].x[3]=1;k[6].x[4]=1;k[6].x[6]=1;k[6].x[7]=1;
    //movr 8ghi
    k[7].x[6]=1;k[7].x[7]=1;k[7].x[8]=1;
    //move 9efhi
    k[8].x[4]=1;k[8].x[5]=1;k[8].x[7]=1;k[8].x[8]=1;
    int v=0;
    while(bmoves[0]==0){v++;dfs(a,v);}
    for(int i=bs-1;i>0;i--)fout<<bmoves[i]+1<<" ";
    fout<<bmoves[0]+1;
    fout<<endl;
    return 0;
}