//STEPS
#include<iostream>
using namespace std;
int main() {
    int N, H, L, steps=1;
    char znak;
    cin>>N>>H>>L;
    cin>>znak;
    for (int j=0;j<N;j++)
     {
        //��� ���� �� ��������� ������� �������
        for (int i=0;i<L;i++) cout << znak;
        //��� ���� � ������ �� ��������� 1-� �������
        if (j==0) cout << znak;
        //��� ���� � �������� 
        if (j+1==N) {
        for (int i=0;i<H-2;i++) 
        {
            cout << endl << znak;
            
            for (int c=0;c<(steps*(L-1))+j;c++) cout << " ";
            cout << znak;
        }
        } else {
        for (int i=0;i<H-1;i++) {
            cout << endl << znak;
            for (int c=0;c<(steps*(L-1))+j;c++) cout << " ";
            cout << znak;
        } }
        steps++;
    }
    cout << endl;
    for (int i=0;i<N*L+1;i++) cout << znak;
    cout << endl;
    system("pause");
    return 0;
}
