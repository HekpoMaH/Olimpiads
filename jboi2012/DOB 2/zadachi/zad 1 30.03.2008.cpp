#include<iostream>
using namespace std;
int main()
{
    long long int n,c;//���� � ������� � �������
    cin>>n;//��������� n
    long long int nn;//���� � ������� �� n
    nn=n;
    int br=0;//���� � �������
    while(nn!=0)
    {
                c=nn%10;
                if(c%2==0){br++;}//��� � ����� �� ����������
                nn=nn/10;//���� � ������ �����
    }
    if(br==0){cout<<"No"<<endl;}
    else{cout<<br<<endl;}//��������� ���� ��� ��� �����
    system("pause");
    return 0;
}
