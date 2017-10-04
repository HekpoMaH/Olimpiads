/*
ID: dobrikg1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int n,ys,yend,ms=1,mend=12,ds=1,dend=1,dofw;
int tht[9];
bool isly(int y)
{
    if((y%4==0&&y%100!=0)||(y%400==0))return true;
    return false;
}
int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    fin>>n;
    ys=1900;yend=1900+n-1;
    ms=1;mend=12;ds=1;dend=31;
    //cout<<ys<<" "<<yend<<endl<<ms<<" "<<mend<<endl<<ds<<" "<<dend<<endl;
    dofw=1;
    while(1)
    {
        if(ds==13)tht[dofw]++;
        ds++;
        //cout<<dofw<<" "<<ds<<" "<<ms<<" "<<ys<<endl;
        dofw++;
        if(dofw==8)dofw=1;
        if(ys==yend&&ms==mend&&ds==dend)break;
        if((ms==4||ms==6||ms==9||ms==11)&&ds==30)
        {
            ms++;
            ds=0;
        }
        if(ms==2&&((isly(ys)==true&&ds==29)||(isly(ys)==false&&ds==28)))
        {
            ms++;
            ds=0;
        }
        if((ms==1||ms==3||ms==5||ms==7||ms==8||ms==10)&&ds==31)
        {
            ms++;
            ds=0;
        }
        if(ms==12&&ds==31)
        {
            ms=1;
            ys++;
            ds=0;
        }
        
        
    }
    fout<<tht[6]<<" "<<tht[7]<<" "<<tht[1]<<" "<<tht[2]<<" "<<tht[3]<<" "<<tht[4]<<" "<<tht[5]<<endl;
    return 0;
}
