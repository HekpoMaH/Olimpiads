//zad 17 str 106
#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    int ch=2;
    int i=1;
    int br1=0;//���� ����� ����� �� ��������� � ������
    while(br1<n)
    {
             
    int br=0;//���� ���������� �� ������� ch
    //��������� �� ��������� ���� ���� ����� � ������
    for(int d=2;d<ch;d++)
    {
            if(ch%d==0){br++;}
    }
    if(br==0){
              a[i]=ch;
              br1++;
              i++;
               }
          ch++;   
     }
     for(int i=1;i<=n;i++)
     {
             cout<<a[i]<<" ";
     }
     cout<<endl;
    system("pause");
    return 0;    
    }
         
                             
