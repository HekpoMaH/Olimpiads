#include<iostream>
#include<stack>
using namespace std;
stack<int>digits;
stack<char>znak;
int res=0;
char arr[36];

void compute()
{
     int a,b;
     char zn;
     while( !digits.empty() )
     {
                zn=znak.top();
                a=digits.top();
                digits.pop();
                if(digits.size()>0)
                {
                                   b=digits.top();
                                   digits.pop();
                }
                else if(zn=='*')b=1;
                else b=0;
                if(zn=='+')
                {
                           res=res+a+b;
                           //cout<<a<<" "<<b<<" "<<res<<endl;
                }
                else if(zn=='-')
                {
                     res=res+b-a;
                     //cout<<a<<" "<<b<<" "<<res<<endl;
                }
                else if(zn=='*')
                {
                     res=res+a*b;
                     //cout<<a<<" "<<b<<" "<<res<<endl;
                }
                znak.pop();
     }
            
}
int main()
{
    int ch;
    char zn;
    int br=0;
    int i;
    cin>>arr;
    for(i=0;i<strlen(arr);i++)
    {
                              if(arr[i]=='+' 
                                 || arr[i]=='(' 
                                 || arr[i]==')' 
                                 || arr[i]=='-' 
                                 || arr[i]=='*')znak.push(arr[i]);
                              else 
                              {
                                   int p=arr[i]-'0';
                                   digits.push(p);
                              }
    }

    compute();
    
    cout<<res<<endl;
    return 0;
}
