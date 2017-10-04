#include<iostream>
#include<string>
using namespace std;
int n;
string s;
void convert1()
{
    int rn=(s[1]-'0')*10+s[2]-'0';
    int cn=(s[4]-'0')*10+s[4]-'0';
    while(cn/26>0)
    {cout<<(char)(cn/26+'A');
    cn/=26;}
    cout<<(char)(cn+'A');
    cout<<rn<<endl;    
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s.size()==6)
        {
            if(s[0]=='R'&&s[1]>='0'&&s[1]<='9'&&s[2]>='0'&&s[2]<='9'&&s[3]=='S'&&s[4]>='0'&&s[4]<='9'&&s[5]>='0'&&s[5]<='9')
            {
                convert1();
            }
        }
        //else convert2();
    }
    return 0;
}