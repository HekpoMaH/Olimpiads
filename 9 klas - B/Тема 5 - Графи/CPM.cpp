#include <iostream>
using namespace std;

void Critical_Path (int n, int i[], int j[], int dij[],
               int *s1, int *s2, int *f1, int *f2, int *tf, int *ff)
{
  int k,index,max,min;
  int ti[20],te[20];

  index = 0;
  for (k=0;k<n;k++)
  {
    if ( i[k]==index+1 )  index = i[k];
    ti[k] = 0; te[k] = 9999;
  }
  for (k=0;k<n;k++)
  {
    max = ti[i[k]] + dij[k];
    if ( ti[j[k]]<max ) ti[j[k]] = max;
  }
  te[j[n-1]] = ti[j[n-1]];
  for (k=n-1;k>=0;k--)
  {
    min = te[j[k]] - dij[k];
    if ( te[i[k]]>min ) te[i[k]] = min;
  }
  for (k=0;k<n;k++)
  {
    s1[k] = ti[i[k]]; f1[k] = s1[k] + dij[k];
    f2[k] = te[j[k]]; s2[k] = f2[k] - dij[k];
    tf[k] = f2[k] - f1[k]; ff[k] = ti[j[k]] - f1[k];
  }
}

int main()
{
  int n;      // ќбщее количество работ по проекту
              // (количество ребер ориентированного графа).
  int i[20];  // ¬ектор-пара, представл€юща€ k-ю работу,
  int j[20];  // котора€ понимаетс€ как стрелка, св€зыва-
              // юща€ событие i[k] с событием j[k]
              // √раф задан массивом ребер:
              // (i[0],j[0]),(i[1],j[1]),...,(i[n-1],j[n-1])
              // ƒолжно быть выполнено:
              // i[0]=1, i[k]<i[k+1], i[k]<j[k].
  int dij[20];// dij[k] - продолжительность k-й операции.
  int s1[20]; // s1[k] - самый ранний срок начала k-й операции.
  int s2[20]; // s2[k] - самый поздний срок начала k-й.
  int f1[20]; // f1[k] - самый ранний срок завершени€ k-й.
  int f2[20]; // f2[k] - самый поздний срок завершени€ k-й операции.
  int tf[20]; // tf[k] - полный резерв времени k-й операции.
  int ff[20]; // ff[k] - свободный резерв времени k-й операции.
  int k;      // ѕараметр цикла.

  cout << "Total project activities : ";//брой дейности
  cin >> n;
  for (k=0;k<n;k++)
  {
     cout << "Beginning and end of edge and duration: "; //Ќачало и край на ребро и продължителност
     cin >> i[k] >> j[k] >> dij[k];
  }
  Critical_Path (n,&i[0],&j[0],&dij[0],&s1[0],&s2[0],&f1[0],&f2[0],&tf[0],&ff[0]);
  //¬ывод результатов.
  cout << "The earliest start date:           ";
  for (k=0;k<n;k++) cout << s1[k] << " "; cout << endl;
  cout << "The deadline for the start:        ";
  for (k=0;k<n;k++) cout << s2[k] << " "; cout << endl;
  cout << "The earliest date for completion:  ";
  for (k=0;k<n;k++) cout << f1[k] << " "; cout << endl;
  cout << "The deadline for completion:       ";
  for (k=0;k<n;k++) cout << f2[k] << " "; cout << endl;
  cout << "Floating time:                     ";
  for (k=0;k<n;k++) cout << ff[k] << " "; cout << endl;
  cout << "Full-time reserve:                 ";
  for (k=0;k<n;k++) cout << tf[k] << " "; cout << endl;
  // ќпределение  критического  пути.  ритический путь задаетс€
  // стрелками, соедин€ющими событи€, дл€ которых полный резерв
  // времени равен нулю.
  cout << "The critical path:                 " << 1 << " ";
  for (k=0;k<n;k++)
   if ( tf[k]==0 ) cout << j[k] << " ";
  return 0;
}
/*
5
1 2 20
1 4 50
2 3 25
2 4 60
3 4 15
*/
