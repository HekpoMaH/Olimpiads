#include<iostream>
using namespace std;
char text[6000],red[100][61],ch,duma[6000][30],buffer[61];
int n,i=0,j=0,ir=0,x,br,brd=0;
void initstr(char a[])
{    int i;
     for(i=0;i<strlen(a);i++)
     a[i]=' ';
}
int brsim(void)
{
     int i,j=0;
     for(i=0;i<strlen(buffer);i++)
     {
                      if(red[x][i]!=' ')
                      j++;
     }
     return j;
}
int  brdum(void)
{
     int i,j=0;
     for(i=0;i<strlen(buffer);i++)
     {
                      if((red[x][i]!=' ') && (red[x][i+1]==' '))  
                       j++;
                       }j++;
                       return j;
}
int broint(void)
{    int a=brsim();
     return 61-a;
}
                       
int main()
{
    cin>>n;
    cin.getline(buffer,61,'\n');
    for(x=0;x<n-1;x++)
    {
           cin.getline(buffer,61,'\n');
           for(br=0;br<61;br++)
           red[x][br]=buffer[br];
           initstr(buffer);
             cout<<brsim()<<endl<<broint()<<endl<<brdum()<<endl<<endl;
          }
           
                
           
   
                        
    system("pause");
    return 0;
}
                         
                         
                         
       
