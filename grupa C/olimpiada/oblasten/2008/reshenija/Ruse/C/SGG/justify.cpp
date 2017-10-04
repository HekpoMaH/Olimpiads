#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,a[n];
    getline(cin,s);
    int br=0;
    for(int i=0; i<n; i++)while(s[br]!='\n'){ a[i]+=s[br]; br++; }
    //                      BEGIN
    int b,sub;
    for(int i=0; i<(n-1); i++)
    {
        b=0;
        for(int j=0; j<a[i].length(); j++)if(a[i][j]!=' ')b++;
        sub=a[i].length()/b;
        for(int j=0; j<a[i].length(); j++)
        {
            if(a[i][j]!=' ')cout<<a[i][j];
            if(a[i][j]==' ' && a[i][j-1]!=' ')for(int p=0; p<sub; p++)cout<<' ';
        }
        cout<<endl;
    }
    for(int i=0; i<a[n-1].length(); i++)
    {
        if(a[n-1][i]!=' ')cout<<a[n-1][i];
        if(a[n-1][i]==' ' && a[n-1][i-1]!=' ')cout<<' ';
    }
    cout<<endl;
    //                  END
    return 0;
}
