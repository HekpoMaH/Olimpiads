#include<iostream>
#include<string>
using namespace std;
long n,i,k,o,p,br1,br2,bra,brc,brt,brg,brp,bri;
string  x[6];

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
                       cin>>x[i];
    }
    for(i=1;i<=n;i++){
                       p=x[i].size();
                       bra=0;
                       brc=0;
                       brt=0;
                       brg=0;
                       bri=0;
                       brp=0;
                       for(o=0;o<=p-1;o++)
                       {
                                        if(x[i][o]=='A')    bra++;
                                        if(x[i][o]=='C')    brc++;
                                        if(x[i][o]=='T')    brt++;
                                        if(x[i][o]=='G')    brg++;
                                        if(x[i][o]=='P')    brp++;
                                        if(x[i][o]=='I')    bri++;
                       }        
                       br1=bra+brc+brt;
                       br2=brg+bri+brp;
                       if(br1>br2) cout<<"CAT"<<endl;
                       else 
                       if(br2>br1) cout<<"GPI"<<endl;
                       else 
                       if(br2==br1 && br2!=0 && br1!=0) cout<<"CAT-GPI"<<endl;
                       else
                       cout<<"UFO"<<endl;
    }     
    // system("pause");
    return 0;
}
    
    
