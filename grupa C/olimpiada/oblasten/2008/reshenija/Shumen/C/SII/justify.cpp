#include<iostream>
#include<string>
using namespace std;
string s;
char ch;
int n,i,k,p,m,j,k1,k2,p1,p2,m1,g,h;
int main()
{
    cin>>k;
    cin.get(ch);
    for(j=1;j<k;j++)
    {
        getline(cin,s);
        n=s.size();
        for(i=0;i<n;i++)
        {
           if(s[i]!=' ')p++;
           if(s[i]==' '&&i>0&&s[i-1]!=' ')m++; 
        }
        if(s[n-1]!=' ')m++;
        if(m==1)k2=p1=0;
        else{
        k1=60-p;
        k2=k1/(m-1);
        p1=k1%(m-1);}
        for(i=0;i<n;i++)
        {
            if(s[i]!=' '){cout<<s[i];p2++;}
            else
            {
                if(p2)
                {
                    m1++;
                    if(m1<m){
                    h=k2;
                    if(p1>0)h++;
                    p1--;
                    for(g=0;g<h;g++)
                    cout<<' ';}
                }
                p2=0;
            }
        }
        cout<<endl;
        k1=k2=p=p1=p2=m=m1=h=0;
    }
    getline(cin,s);
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]==' '&&i>0&&s[i-1]!=' ')m++; 
    }
    if(s[n-1]!=' ')m++;
    for(i=0;i<n;i++)
    {
        if(s[i]!=' '){cout<<s[i];p++;}
        else
        {
            if(p)
            {
                if(m>1)
                {
                    cout<<' ';
                    m--;
                }
            }
            p=0;
        }
    }
    cout<<endl;
}
