#include<iostream>
using namespace std;
long long ura,i,j,brch,pom,nomer,poslcifri,polchisla[2],chislo,br;
int main(){
ura=0;
cin>>brch;
for(i=0;i<brch;i++)
{
    poslcifri=1;
    br=0;
    nomer=0;
    cin>>chislo;
    if(chislo==1)
    {
      ura++;
    }
    else
    {
        for(j=1;j<=chislo;j=j*10)
        {
            nomer++;
        }
        pom=chislo*chislo;
        for(j=0;j<nomer;j++)
        {
          poslcifri=poslcifri*10;
        }
        polchisla[0]=pom%poslcifri;

        if(poslcifri>pom)
        {
          poslcifri=poslcifri/10;
        }
        polchisla[1]=pom/poslcifri;
        if(polchisla[1]+polchisla[0]==chislo)
        {
          ura++;
        }
    }
}
cout<<ura<<endl;
return 0;
}
