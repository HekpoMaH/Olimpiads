#include <iostream>
using namespace std;

int main()
{long long a,b,c=1;
cin>>a>>b;
while (a!=b)
{if (a>b)a=a-b;
else b=b-a;
c++;
}
cout<<c<<endl;
return 0;
}  

