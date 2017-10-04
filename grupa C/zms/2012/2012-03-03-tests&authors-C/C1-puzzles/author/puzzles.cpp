//Task: Puzzles
//Author: Pano Panov

#include <cstdlib>
#include <iostream>
#include <string.h>
#define MAXDIGITS 5

using namespace std;

typedef struct {
                char LtName;    // ������ �������� �����
                int val;        // ������ ��������
                int nozero;     // ��� � ����� � ����� �� ������� - 1; ����� - 0;
               }lsubst;
lsubst Abc[MAXDIGITS*3];        // ������ �� �������, ����� �� ������ � �����������
int n=0;                        // ���� �����
long long li, upper, ost, del;
 // ������� �� ��������� �� ������ ����
int LeadingZero()
    {
     int j;
     for(j=0; j<n; j++)
        {
         if(Abc[j].val == 0 && Abc[j].nozero ==1) return 1;
        }
     return 0;
    }
 // ������� �� ��������� �� ������� �����
 int SameDigits()
     {
      int j, k;
        for(j=0; j<n-1; j++)
           {
            for(k=j+1; k<n; k++)
                if(Abc[k].val == Abc[j].val) return 1;
           }
      return 0;
     }

int main()
{
    char EqStr[MAXDIGITS*4], Buff[MAXDIGITS*4], p[MAXDIGITS+1], q[MAXDIGITS+1], r[MAXDIGITS+1];
    int NumOfSolutions=0;
    int i, j, k;

    cin >> EqStr;
    // ������ �� ��������� ���
    for(i=0; EqStr[i]; i++)
       {
         if(isupper(EqStr[i]))
           { // ������ �������� �����
             for(j=0, k=0; j<n; j++)
                {
                 if(Abc[j].LtName == EqStr[i])
                   { // ��� � � �������
                    if((i==0)||(EqStr[i-1]=='+')||(EqStr[i-1]=='='))Abc[j].nozero = 1;
                    k=1;
                    break;
                   }
                }
             if(k==0)
               { // ���� ����� - �������� � �������
                Abc[n].LtName = EqStr[i];
                Abc[n].val = 0;
                if((i==0)||(EqStr[i-1]=='+')||(EqStr[i-1]=='='))Abc[n].nozero = 1;
                else Abc[n].nozero = 0;
                n++;
               }
           }
       }

     for(i=0, upper=1; i<n; i++)
        {
         // ���������� �� ������� ������� �� ���������� ����������
         upper *= 10;
        }
    // ������ ����� - ���������� ���������� ������� ������ �������� ����������
    for(li=0; li<upper; li++)
       {
        // �������� �� ������� � ����������� �� � ������ val �� ����������� �����
        del = upper /10;
        for(j=0, ost=li; j<n; j++)
           {
            Abc[j].val=ost/del;
            ost = ost%del;
            del/=10;
           }
        // ��������� ������������� �� ������� ����� �� �������� �����
        if(SameDigits()) continue;
        // ��������� �� ������ ����
        if(LeadingZero()) continue;
        // ������� �� ������� ��� ����������� ����� � ����� �� �������� ���������
        strcpy(Buff, EqStr);
        for(i=0; Buff[i]; i++)
           {
            if (isupper(Buff[i]))
               {
                for(j=0; j<n; j++)
                   {// �� ������� �� ������� ��������� �����������
                    if(Abc[j].LtName == Buff[i]){Buff[i]=Abc[j].val+'0';}
                   }
               }
           }
        //cout << "Buff:" << Buff << endl;
        // ���� ������������ ����� �� ������� �� �����������
        strcpy(p, strtok (Buff,"+"));
        strcpy(q, strtok (NULL,"="));
        strcpy(r, strtok (NULL,""));
        if(atoi(p)+atoi(q)==atoi(r))
            {
             /*cout << p<<"+"<<q<<"="<<r<<endl;*/
             NumOfSolutions++;
            }
       }
    cout << NumOfSolutions << endl;
    return 0;
}
// ABCD + BDC = EAEA
// 1538+583 = 2121
// 1547+574 = 2121, 1574+547 = 2121,
// 1583 + 538 = 2121, 3658 + 685 = 4343, and 3685 + 658 = 4343.
