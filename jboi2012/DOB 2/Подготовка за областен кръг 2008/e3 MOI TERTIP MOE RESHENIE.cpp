#include<iostream>
using namespace std;
int main()
{
    int br=0;
    int l=0;
    char c;
    do
    {
        cin.get(c);
        if(c>='0'&&c<='9'&& !l){l=1;}
        if((c<'0'||c>'9')&&l){
                              br++; 
                              l=0;
                              }
    }
    while(c!='.');
    cout<<br<<endl;
    return 0;
}
