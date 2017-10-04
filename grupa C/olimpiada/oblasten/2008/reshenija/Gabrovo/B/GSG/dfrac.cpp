#include<iostream>
#include<string>
using namespace std;
unsigned long long a,b,k,p;
int cifa=0,cifb=0;
short k1[18];
short mark[18];
short add=0;
bool plussed=0,there=0,bug=0;
void input()
{
     cin>>a>>b>>k>>p;
     }
void edit()
{
     for(int i=0;i<18;i++)
     {
             k1[i]=k%10;k=k/10;}
}
void plusplus()
{
     add=1;
     for(int j=0;j<18;j++)
     {
             if(mark[j]<9){mark[j]+=add;add--;break;}
             else{mark[j]=0;}
             }
}
bool imthere()
{
     for(int x=0;x<18;x++)
     {
             if(k1[x]!=mark[x]){return false;}
             }
             there=true;
             return true;
}
void writeoff(int rem)
{
     if(imthere()||there==true){rem--;}
     for(int r=rem;r>0;r--)
     {cout<<"0";}
}
void dothemath()
{
     int opa=a,opb=b;
     while(p>0)
     {
     if(imthere()||there==true){cout<<opa/opb;p--;bug=true;}
     if(opa%b==0){if(bug==true){p++;bug=false;}writeoff(p);break;}
     plusplus();opa=(opa%b)*10;
     }
}
     
            
    
    
int main()
{
    input();
    edit();
    mark[0]=0;
    dothemath();
    cout<<endl;
    return 0;
}
