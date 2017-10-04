#include<iostream.h>
#include<stdlib.h>
long m,n,ran;
main()
{
cin>>m>>n;
randomize();
for(n=1;n<=m;n++)
 ran++;

 ran=random(m+1);
  cout<<ran<<endl;
return 0;
}