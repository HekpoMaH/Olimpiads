#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int fact(int k)
{
    int temp=1,i;
    for(i=2;i<=k;i++) temp*=k;
    return temp;
}
 //string s;
int rec(int b, int e)
{int i;
  //  for(i=0;i<s.size();i++);
}




int main()
{
  char s[100];
    scanf("%s",&s);
   // s+='\0';
//    cout<<rec(s,0,s.size()-1)<<endl;
    int br=0,i; 
    for(i=0;i<strlen(s);i++) if (s[i]=='/' ||s[i]=='*' ||s[i]=='-' ||s[i]=='+' ||s[i]=='^' )br++;
    printf("%d\n",(br%3+1)*(br%5+1));
   // system("pause");
    return 0;
}
