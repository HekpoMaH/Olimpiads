#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int cmp(const void *a,const void*b)
{
 const char *p = (const char*)a;
 const char *q = (const char *)b;
 if(*p<*q)
          return -1;
 if(*p>*q)
          return 1;
 return 0;
}
char db[300][9001];
int main(void)
{
 char a[31],buf[901];
 int n,m,i,j,cnt=0,size,k=0;
 int error=0;
 cin>>n>>m;
 for(i=0;i<n;i++,error=0)
 {
        for(j=0;j<m;j++)
        {
                cin>>a;
                memcpy(&buf[m*j],a,m*sizeof(char));
                buf[m*m] = 0;
        }
        qsort((void *)buf,m*m,sizeof(char),cmp);
        k=0;
        while(k < cnt)
        {
                 if(!strcmp(buf,db[k]))
                                    {
                                                error=1;
                                                break;
                                    }
                 k++;
        }
        if(!error)
        {
                strcpy(db[cnt],buf);
                cnt++;

        }
 }
 cout<<cnt<<endl;
 return 0;
}
