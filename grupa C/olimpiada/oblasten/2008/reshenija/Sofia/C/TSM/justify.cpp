#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct line
{
    char a[32][64];
    int l[32], n;
    void read()
    {
        n=0; l[31]=0;
        char *s, *g; g=s;
        s=new char[64];
        gets(s);
        int i=0;
        while(sscanf(s, "%s", a[i]))
        {
            l[i]=strlen(a[i]);
            while(*s==' ') s++; s+=l[i];
            l[31]+=l[i++];
            while(*s==' ') s++; if(*s=='\0') break;
            n++;
        }
        delete[] g;
    }
    void write()
    {
        int bsz, bi; //blanksize, blankincreased
        bsz=(60-l[31])/n;
        bi=(60-l[31])%n;
        int i, j;
        for(i=0; i<n; i++)
        {
            cout<<a[i];
            for(j=0; j<bsz; j++) printf(" ");
            if(i<bi) printf(" ");
        }
        cout<<a[n]<<endl;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    char a[100];
    gets(a);
    line l;
    for(int i=1; i<n; i++)
    {
        l.read();
        l.write();
    }
    l.read();
    for(int i=0; i<l.n; i++) cout<<l.a[i]<<' ';
    cout<<l.a[ l.n ]<<endl;
    return 0;
}
