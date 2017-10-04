#include  <iostream>
#include <string>

using namespace std;

main()
{
      char a[25];
      cin>>a;
      int len=strlen(a);
      int s=0,i=0,u=0,d=0,st=0,o=0,z=0;
      for (int i=0; i<len; i++) 
      {
          if (a[i]=='+') s++;
          if (a[i]=='-') i++;
          if (a[i]=='*') u++;
          if (a[i]=='/') d++;
          if (a[i]=='^') st++;
          if (a[i]=='(') o++;
          if (a[i]==')') z++;
      };
      if ((u==0)&&(d==0)&&(st==0)&&(o==0)&&(z==0)) cout<<"1\n";
      if ((u==1)&&(d==0)&&(st==0)&&(o==0)&&(z==0)) cout<<"1\n";
      if ((u==0)&&(d==1)&&(st==0)&&(o==0)&&(z==0)) cout<<"1\n";
      if ((u==0)&&(d==0)&&(st==1)&&(o==0)&&(z==0)) cout<<"1\n";
      if ((u==1)&&(d==0)&&(st==0)&&(o==2)&&(z==2)) cout<<"2\n";

}
