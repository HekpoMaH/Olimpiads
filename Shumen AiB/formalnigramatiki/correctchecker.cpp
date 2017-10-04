#include<iostream>
#include<string>
using namespace std;
string s;
int expr(int i);
int add(int i)
{
    while(s[i]=='+')
    {
        i=expr(i+1);
        if(i==-1)return -1;
    }
    return i;
}
int term(int i)
{
    i=expr(i);
    if(i==-1)return -1;
    i=add(i);
    return i;
}
int expr(int i)
{
    switch(s[i])
    {
        case 'x':i++;break;
        case '(':
               i=term(i+1);
               if(i==-1)return -1;
               if(s[i]==')')i++;
               else return -1;
               break;
        default: return -1;
    }
}
int main()
{
    cin>>s;
    if(expr(0)==-1)cout<<"error"<<endl;
    else cout<<"correct"<<endl;
    return 0;
}
