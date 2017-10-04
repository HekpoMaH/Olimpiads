#include<iostream>
using namespace std;
int main()
{
    char ch;
    cin>>ch;
    int br=1;
    while(ch!='.')
    {
                  if(ch>='a'&&ch<='z'&&br%2==1)ch=ch-('a'-'A');
                  if(ch>='A'&&ch<='Z'&&br%2==0)ch=ch+('a'-'A');
                  cout<<ch;
                  br++;
                  cin>>ch;
    }
    cout<<"."<<endl;
    system("pause");
    return 0;
}
