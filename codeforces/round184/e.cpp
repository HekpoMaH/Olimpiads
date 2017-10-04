#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[5009];
int grundy[5009],mex[5009],n,totalxor;
int main()
{
    gets(s);
    for(int i=1;i<5005;i++)
    {
        memset(mex,0,sizeof(mex));
        for(int j=0;j<i;j++)
        {
            int left=max(0,j-1);
            int right =max(0,i-j-2);
            int txor=grundy[left]^grundy[right];
            if(txor<5005)mex[txor]++;
        }
        for(int j=0;;j++)
        {
            if(!mex[j])
            {
                grundy[i]=j;
                break;
            }
        }
    }
    n=strlen(s);
    {
        for(int i=1;i<n-1;i++)
        {
            if(s[i-1]==s[i+1])
            {
                int j=i;
                while(j+2<n&&s[j]==s[j+2])j++;
                totalxor^=grundy[j-i+1];
                i=j+1;
            }
        }
    }
    if(totalxor!=0)
    {
        puts("First");
        for(int i=1;i<n-1;i++)
        {
            if(s[i-1]==s[i+1])
            {
                int j=i;
                while(j+2<n&&s[j]==s[j+2])j++;
                int len=j-i+1;
                int nowxor=totalxor^grundy[len];
                for(int k=0;k<len;k++)
                {
                    int left=max(0,k-1);
                    int right=max(0,len-k-2);
                    int resxor=nowxor^grundy[left]^grundy[right];
                    if(resxor==0)
                    {
                        printf("%d\n",i+k+1);
                        return 0;
                    }
                }
                i=j+1;
            }
        }
    }
    puts("Second");
}
