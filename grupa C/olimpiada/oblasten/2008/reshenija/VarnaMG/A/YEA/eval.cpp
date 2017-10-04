#include <iostream>   
#include <cstring>

int main()
{
     char a[32];
     int len,i,j;
     gets(a);
     len = strlen(a);
     if(len < 3)
     {
      printf("0\n");
      return 0;
     }
     if(len == 3)
     {
      printf("1\n");
      return 0;
     }
     long long fl,res;
     fl = 0;
     for(i = 0;i < len;i++)
     {
        if(a[i] >= 'a' && a[i] <= 'z' )
          continue;
        else if(a[i] != '+')
        {
            fl = 1;
            break;
        }
     }
     if(fl == 0)
     {
       res = 1;
       for(i = 1;i < len/2+1;i++)
       {
          res*=i;
       }
       printf("%I64d\n",res);
       return 0;
     }
     fl = 0;
     for(i = 0;i < len;i++)
     {
        if(a[i] >= 'a' && a[i] <= 'z' )
          continue;
        else if(a[i] != '-')
        {
            fl = 1;
            break;
        }
     }
     if(fl == 0)
     {
       printf("1\n");
       return 0;
     }
     fl = 0;
     for(i = 0;i < len;i++)
     {
        if(a[i] >= 'a' && a[i] <= 'z' )
          continue;
        else if(a[i] != '*')
        {
            fl = 1;
            break;
        }
     }
     if(fl == 0)
     {
       res = 1;
       for(i = 1;i < len/2+1;i++)
       {
          res*=i;
       }
       printf("%I64d\n",res);
       return 0;
     }
     fl = 0;
     for(i = 0;i < len;i++)
     {
        if(a[i] >= 'a' && a[i] <= 'z' )
          continue;
        else if(a[i] != '/')
        {
            fl = 1;
            break;
        }
     }
     if(fl == 0)
     {
       printf("1\n");
       return 0;
     }
     fl = 0;
     for(i = 0;i < len;i++)
     {
        if(a[i] >= 'a' && a[i] <= 'z' )
          continue;
        else if(a[i] != '^')
        {
            fl = 1;
            break;
        }
     }
     if(fl == 0)
     {
       printf("1\n");
       return 0;
     }
     fl = 0;
     res = 1;
     for(i = 0;i < len;i++)
     {
        if(a[i] >= 'a' && a[i] <= 'z' )
          continue;
        else if(a[i] == '(')
        {
            fl++;
        }
     }
     for(i = 1;i < fl+1;i++)
     {
       res*=i;
     }
     printf("%I64d\n",res);
     return 0;
}

