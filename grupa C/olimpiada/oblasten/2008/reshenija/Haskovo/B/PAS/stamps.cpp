#include <iostream>
using namespace std;
int pari[900];
int br=0,br1=1,s,n,p,suma=0;
int pr(int a)
{
            do
    { 
       if (pari[a]<s)
       { 
       if ((suma + pari[a])>s) a--; else {suma = suma+pari[a];br++;};
       };
       if (pari[a]>s) { if (a!=0) a--;};       
    }
    while (suma != s);
    return br;
}

int main ()
{
    cin >>s>>n;
    for (int i=0;i<n;i++)
    {
        cin>>pari[i];
    }
    sort(pari,pari+n);
    for (int i=0;i<n;i++)
    {
        if (pari[i]==s) {cout <<"1"; return 1;}
    }
    p=n-1;
    cout << pr(p);

    return 0;
}
