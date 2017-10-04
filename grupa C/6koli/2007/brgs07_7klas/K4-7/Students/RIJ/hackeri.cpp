#include<iostream>
#include<string>
using namespace std;
string rev(string x,int n)
{
    int j=n-1;
    for (int i=0;i<j;i++)
    {
        swap(x[i],x[j]);
        j--;
    }
    return x;
}
int main()
{
    string a,s;
    cin>>s;
    int b=s.size();
    a=rev(s,b);
    string c,d="";
    int i,l;
    for (i=0;i<b-1;i++)
    {
        c=s.substr(b-1-i,i+1);
        d=a.substr(0,i+1);
        if(c==d) l=i;
    }
    a.erase(0,l+1);
    cout<<s<<a<<endl;
    return 0;
}

