#include<iostream>
using namespace std;
int main()
{
    int br=0,l=0;
    char ch;
    do
    {
         cin.get(ch);
         if(ch>='0' && ch<='9' && !l){l=1;}
         if(ch<'0' || ch>'9' && l)
         {
                   br++;
                   l=0;
         }
    }
         while(ch=='.');
         cout<<br<<endl;
         system("pause");
         return 0;
}
