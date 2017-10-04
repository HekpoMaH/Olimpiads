#include<iostream>
using namespace std;
char c[30000000],pt[30000000];
int main()
{
long long a, b, k,p,o,i,brn=0;
long long brpt=0;

cin>>a>>b>>k>>p;
a%=b;
//cout<<endl;
for (;;)
    {
    if(a*10>b)break;
    a*=10;
    if (k>1)k--;
        else {cout<<0;p--;}
    brn++;
}
    //cout<<"k"<<k<<endl;
    //cout<<"va:"<<a<<endl; system("pause");
for (;;)
    {
    //for(;;) {if(a>b)break; a*=10;}

    a*=10;
    o=a/b;
    if(a>b)a%=b;
    //cout<<"a:"<<a<<"c[a]:"<<(int)c[a]<<" o:"<<o<<endl;
    if(c[a]==1) break;
    pt[brpt]=o;
    brpt++;
    c[a]=1;
    //cout<<"ka:"<<a<<endl;
    //system("pause");
    }

//cout<<"k"<<k<<" brpt:"<<brpt<<endl;
i=k%brpt-1;
if(i<0)i=brpt+i;
//cout<<"start print:"<<i<<endl;
int br;
for (br=1;br<=p;br++)
    {if(i==brpt)i=0;
    cout<<(int)pt[i];
    i++;
    }
cout<<endl;
return 0;
}
