//�� �� ������ ��������, ����� ������� �� ������������ ���� ����� 2<n<25 � ������ �� ���� �����
//�1, �2, �3, ....�n. �� �� ������ � ������ ����� �� ���� �����, ����� ���� �� ������ � ���������� �����.
// ��� ���� ������, �� �� ������ NO
//����:
// 5
//26 87 -57 238 125
//�����: 3
#include<iostream>
using namespace std;
int main()
{
    int a[25];
    int n;
    int d,c,sb=0,brs=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
            d=abs(a[i]);
            
            while(d!=0)
            {
                       
                       c=d%10;
                       d=d/10;
                       sb=sb+c;
            }
           int br=0;
             while(sb!=0)
            {
                       
                       c=sb%10;
                       sb=sb/10;
                       br++;
            }
         if (br==2){brs++;}   
    }
    if(brs==0){cout<<"NO"<<endl;}
    else{cout<<brs<<endl;}
    system("pause");
    return 0;
}
