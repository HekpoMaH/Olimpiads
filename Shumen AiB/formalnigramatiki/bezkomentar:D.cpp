#include<iostream>
#include<string>
using namespace std;
char ch;
int p;
int main()
{
    p=1;
    char prevch;
    while(cin.get(ch))
    {

        //cout<<ch<<endl;
        switch(p)
        {
            case 1: if(ch=='/')p=2;
                     else cout<<ch;
                     break;
            case 2:
                if(ch=='/')p=3;
                else if(ch=='*')p=4;
                else cout<<prevch<<ch,p=1;
                break;
            case 3:
                if(ch=='\n')cout<<ch,p=1;
                break;
            case 4:
                if(ch=='*')p=5;
                break;
            case 5:
                if(ch=='/')p=1;
                else p=4;
                break;
        }prevch=ch;
    }
    //cout<<p<<endl;
    //cout<<"A"<<endl;
    return 0;
}

