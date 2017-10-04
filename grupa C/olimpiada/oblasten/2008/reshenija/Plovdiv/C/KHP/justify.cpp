#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    long long n,i;
    cin>>n;
    getline(cin,s);
    for(i=1;i<n;i++)
    {
        getline(cin,s);
        int brdumi=0,br=0;
        int k,j,d=s.size();
        for(j=0;j<d;j++)
        if(s[j]!=' ')br++;
        else if(j && s[j-1]!=' ')brdumi++;
        if(s[d-1]!=' ')brdumi++;
        brdumi--;
        if(brdumi==0)
        {
            for(j=0;j<d;j++)
            if(s[j]!=' ')cout<<s[j];
            for(j=1;j<=60-br;j++)
            cout<<' ';
        }
        else
        {
        int w=(60-br)/brdumi+1,o=(60-br)%brdumi;
        for(j=0;j<d;j++)
        {
            if(s[j]!=' ')cout<<s[j];
            else if(brdumi && j && s[j-1]!=' ')
            {
                brdumi--;
                o--;
                if(o==-1)w--;
                for(k=1;k<=w;k++)
                cout<<' ';
            }
        }
        }
        cout<<endl;
    }
    getline(cin,s);
    int d=s.size();
    for(i=0;i<d;i++)
    if(s[i]!=' ' || (i && s[i-1]!=' '))cout<<s[i];
    cout<<endl;
}
