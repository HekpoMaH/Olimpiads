#include<iostream.h>
#include<stdio.h>
long long a,b,k,p,i,a1;
int main()
{ cin>>a>>b>>k>>p;
k--;
    while(k>0)
    {if(a<b)  { a*=10; }
      else { a%=b; k--; }
    }
   while(p>0)
    {
      if(a<b)
      { a*=10;
       if(a<b)  { printf("0"); p--; }
      }
      else { a1=a; a%=b;
	     printf("%d",(a1/b));  p--; }
    }
    cout<<endl;
// system("pause");
    return 0;
}
