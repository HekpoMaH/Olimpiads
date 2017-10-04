//
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
/*int NOK(unsigned long long int a,unsigned long long int b)
{
    unsigned long long int r=0,a1=a,b1=b;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}*/
int main()
{

    ios::sync_with_stdio(false);
    unsigned long long int sum,k=1;
    int n;
    cin>>n;    
    if(n==1){k= 1;}
    if(n==2){k= 2;}
    if(n==3){k= 6;}
    if(n==4){k= 12;}
    if(n==5){k= 60;}
    if(n==6){k= 60;}
    if(n==7){k= 420;}
    if(n==8){k= 840;}
    if(n==9){k= 2520;}
    if(n==10){k= 2520;}
    if(n==11){k= 27720;}
    if(n==12){k= 27720;}
    if(n==13){k= 360360;}
    if(n==14){k= 360360;}
    if(n==15){k= 360360;}
    if(n==16){k= 720720;}
    if(n==17){k= 12252240;}
    if(n==18){k= 12252240;}
    if(n==19){k= 232792560;}
    if(n==20){k= 232792560;}
    if(n==21){k= 232792560;}
    if(n==22){k= 232792560;}
    if(n==23){k= 1059261584;}
    if(n==24){k= 620448401733239439360000;}
    if(n==25){k= 1371508296;}
    if(n==26){k= 433293264;}
    if(n==27){k= 1837710049;}
    if(n==28){k= 618198384;}
    if(n==29){k= 18446744072192118748;}
    if(n==30){k= 18446744073105890404;}
    if(n==31){k= 18446744072042515316;}
    if(n==32){k= 18446744073243505056;}
    if(n==33){k= 18446744072354119648;}
    if(n==34){k= 1157236512;}
    if(n==35){k= 18446744071920193248;}
    if(n==36){k= 872389344;}
    if(n==37){k= 952000140;}
    if(n==38){k= 842310496;}
    if(n==39){k= 18446744073163246159;}
    if(n==40){k= 18446744071887719960;}
    if(n==41){k= 18446744072023930016;}
    if(n==42){k= 1479166440;}
    if(n==43){k= 18446744072707252360;}
    if(n==44){k= 433958940;}
    if(n==45){k= 18446744073396715168;}
    /*for(int j=1;j<=45;j++)
    {
        for(int i=2;i<=j;i++)
        {
            k=NOK(i,k);
        }
        cout<<"if(n=="<<j<<"){k="<<" "<<k<<";}"<<endl;
    }*/
    sum=k;
    for(int i=2;i<=n;i++)
    {
        sum=sum+k/i;
    }
    cout<<sum/k<<" "<<sum%k<<" "<<k<<endl;
    return 0;
}