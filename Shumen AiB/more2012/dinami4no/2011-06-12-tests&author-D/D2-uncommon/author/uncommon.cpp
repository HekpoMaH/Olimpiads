#include <iostream>
using namespace std;
int main()
{long long a,b,p,q,t,r;
 int n,d,c,e,f;
 cin>>a>>b>>n>>d;
 //���-����� ��� ������� (���) �� n � d
 e=d;f=n;//�������� ����������
 do
 {c=e%f;
  if (!c) break;
  e=f;
  f=c;
 }while (true);
 //��� ��� � � f
 n/=f;d/=f;//����������� �� f
 c=0;//����� �� ���������� �����
 //������ ������� p � ��������� [a,b]
 t=a/n;//t �� ����� ������� ��������, �� ����� pt>=a
 if (a%n) t++;//��� �� �� ���� ����� - ����������
 p=t*n;q=t*d;//������ p/q=n/d
 while (p<=b)
 {
   r=0;//� r �� ������� p "�������"
   while (p)
   {r=10*r+p%10;
    p/=10;
   }
   if (r==q) c++; //��� ��������� �� p � ����� q - �����
   t++;
   p=t*n;q=t*d;//���������� ����
 }
 cout<<c<<endl;
 return 0;
}
