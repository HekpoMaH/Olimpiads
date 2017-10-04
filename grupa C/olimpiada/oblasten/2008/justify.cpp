#include<iostream>
#include<string>
using namespace std;
char buf[100],c;
void just(int i)
{
    int br=0,k,k1,p,q,pi;
    char b[100];
    for(k=i-1;k>0;k--)if(buf[k]==' ')br++;
    p=(60-i)/br;
    q=(60-i)%br;
    for(k=0,k1=0;k<i;k++)
    {
       if(buf[k]!=' ')b[k1++]=buf[k];
       else
       {
          b[k1++]=' ';
          for(pi=1;pi<=p;pi++)b[k1++]=' ';
          if(q>0){b[k1++]=' ';q--;}
       }
    }
    b[k1]='\0';cout<<b;
}
int main()
{
   int i,br,flag,N;
   cin>>N;
   for(br=1;br<=N;br++)
   {
      do cin>>buf[0]; while(buf[0]==' ');
      i=1;
      flag=0;
      while(1)
      {
        cin>>c;
        switch(c)
        {
            case '\n':  if(buf[i-1]==' ') {i--;buf[i]='\0';}
                        else buf[i]='\0';
                        flag=1;
                        break;
            case ' ':   if(buf[i-1]!=' ') buf[i++]=c;
                        break;
            default:    buf[i++]=c;
         }
         if(flag) break;
      }
      if(br!=N) just(i);
      else cout<<buf;
   }
   return 0;
}
