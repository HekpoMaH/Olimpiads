// �� �� ������ ��������, ����� ������� �� ������������ ���� ����� 1<n<216
// � ������ �� ���������� ����� �1, �2, �3....�n, ���� ����� ������ � ������� ���� �� �������, ����� �� ������.
//��� ���� ������, ���� ������ NO.
// ����:6
//4 5 43 12 15 7
//�����: 5 43 7
#include<iostream>
using namespace std;
int main()
{
    int a[216];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            cin>>a[i];
    }
    int l=0,br=0;
    for(int i=1;i<=n;i++)
    {
            l=0;
            for(int d=2;d<a[i];d++)
            {
                    if(a[i]%d==0)
                    {
                                 l++;
                    }
            }
            if(l==0){
                           cout<<a[i]<<" ";
                           br++;
                    }
    }
    if(br==0){cout<<"NO"<<endl;}
    else{cout<<endl;}
    system("pause");
    return 0;
}
            
            
                                 
     
                    
