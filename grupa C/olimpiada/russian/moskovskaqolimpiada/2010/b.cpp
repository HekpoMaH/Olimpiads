#include<iostream>
#include<string>
using namespace std;
string d,d1;
int l,l2;
int main()
{
    cin>>d;
    int k=d.size();
    for(int i=0;i<k-2;i++)d1+=d[i];
    if(d[d.size()-1]!='0'||d[d.size()-2]!='0'){l2=1;d1[d1.size()-1]++;}
    int n=d1.size();
    //cout<<n<<endl;
    for(int i=n-1;i>=0;i--)
    {
        //cout<<"a"<<endl;
        if(d[i]>'9'&&i!=0){d[i]='0';d[i-1]++;}
        if(d[i]>'9'&&i==0){l=1;d[i]='0';}
    }
    if(l==1)cout<<"1";
    if(d1.size()==0)cout<<l2<<endl;
    cout<<d1<<endl;
    return 0;
}
