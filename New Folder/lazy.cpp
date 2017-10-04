#include<iostream>
using namespace std;
int main()
{
    char ch;
    int br=0,br2=1;
    cin>>ch;
    while(ch!='.')
    {
                br++;
                cin>>ch;
    }
    long long int a=1,b=1,c=0;
    while(c<br)
    {
               c=a+b;
               a=b;
               b=c;
               br2++;
    }
    cout<<br2-1<<endl;
    system("pause");
    return 0;
}
