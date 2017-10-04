#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string fiw,sew;
string code1,code2,w1,w2,code;
char e1[1<<17],e2[1<<17];
string codefor1(string x)
{
    //cout<<x.size()<<endl;
    if(x.size()<=2)
    {
        if(x[0]-'a'>x[1]-'a')
        {
            string re="";
            re=re+x[1];re=re+x[0];
            //cout<<"re="<<re<<endl;
            code1+="1";return re;

        }
        if(x[0]-'a'<=x[1]-'a')
        {
            string re="";
            re+=x[0];re+=x[1];//cout<<"re1="<<re<<endl;
            code1+="0";
            return re;
        }
    }
    string f1="";
    for(int i=0;i<x.size()/2;i++)f1=f1+x[i];
    string ff1=codefor1(f1);
    string f2="";
    for(int i=x.size()/2;i<x.size();i++)f2=f2+x[i];
    string ff2=codefor1(f2);
    //cout<<"ff1="<<ff1<<" "<<"ff2="<<ff2<<" "<<"f1="<<f1<<" "<<"f2="<<f2<<endl;
    if(ff1>ff2){code1+="1";return ff1+ff2;}
    if(ff1<ff2||ff1==ff2){code1+="0";return ff2+ff1;}
}
string codefor2(string x)
{
    //cout<<x<<endl;
    if(x.size()==2)
    {
        if(x[0]-'a'>x[1]-'a')
        {
            string re="";
            re=re+x[1];re=re+x[0];
            //cout<<"re="<<re<<endl;
            code2+="1";
            return re;
        }
        if(x[0]-'a'<=x[1]-'a')
        {
            string re="";
            re+=x[0];re+=x[1];//cout<<"re1="<<re<<endl;
            code2+="0";
            return re;
        }
    }
    string f1="";
    for(int i=0;i<x.size()/2;i++)f1=f1+x[i];
    string ff1=codefor2(f1);
    string f2="";
    for(int i=x.size()/2;i<x.size();i++)f2=f2+x[i];
    string ff2=codefor2(f2);
    //cout<<"ff1="<<ff1<<" "<<"ff2="<<ff2<<" "<<"f1="<<f1<<" "<<"f2="<<f2<<endl;
    if(ff1>ff2){code2+="1";return ff1+ff2;}
    if(ff1<ff2||ff1==ff2){code2+="0";return ff2+ff1;}
}
void mercod(string c1,string c2)
{
    int x1=c1[c1.size()-1]-'0',x2=c2[c2.size()-1]-'0';
    //cout<<x1<<" "<<x2<<" "<<(x1^x2)<<endl;
    x1^=x2;
    string fef1="",fef2="",fef3="",fef4="";
    for(int i=0;i<c1.size()/2;i++)fef1+=c1[i];
    for(int i=c1.size()/2;i<c1.size()-1;i++)fef2+=c1[i];
    for(int i=0;i<c2.size()/2;i++)fef3+=c2[i];
    for(int i=c2.size()/2;i<c2.size()-1;i++)fef4+=c2[i];
    //cout<<c1<<" "<<c2<<" "<<fef1<<" "<<fef2<<" "<<fef3<<" "<<fef4<<" "<<code<<endl;
    if(x1==0)
    {
        //cout<<"F"<<endl;
        code+=x1+'0';if(c1.size()==1)return;
        mercod(fef2,fef4);mercod(fef1,fef3);
    }
    else
    {
        code+=x1+'0';if(c1.size()==1)return;
        mercod(fef2,fef3);mercod(fef1,fef4);
    }
}
void solve()
{
    //ios::sync_with_stdio(false);
    fiw="";sew="";
    code1="";code2="";code="";
    scanf("%s",e1);
    scanf("%s",e2);
    int n=strlen(e1);
    for(int i=0;i<n;i++)fiw+=e1[i],sew+=e2[i];
    w1=codefor1(fiw);w2=codefor2(sew);
    //cout<<fiw.size()<<" "<<sew.size()<<endl;
    mercod(code1,code2);
    reverse(code.begin(),code.end());
    //cout<<w1<<" "<<w2<<endl;
    //cout<<code1<<" "<<code2<<endl;
    if(w1!=w2)printf("No\n");
    else{printf("Yes\n");for(int i=0;i<code.size();i++)printf("%c ",code[i]);printf("\n");}
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}
