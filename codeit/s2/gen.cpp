#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > st;
int main()
{
    ofstream fout("robot.in");
    fout<<1000000000<<" "<<1000000000<<" "<<100000<<endl;
    srand(time(NULL));
    for(int i=1;i<=100000;i++)
    {
        long long x,y;x=rand()*rand()*rand(),y=rand()*rand()*rand();//while(st.find(make_pair(x,x)))!=st.end()x=rand()*rand()*rand(),y=rand()*rand()*rand();
        fout<<x<<" "<<y<<endl;
        //st.insert(make_pair(x,y));
    }
}
