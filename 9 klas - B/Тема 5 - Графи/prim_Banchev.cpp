// �������� �� ��������� �������� ����� �� ��������� ���� �� ���������� �� ����.
// ����: ���� ��� � <����-�������> <����-�����>, ������� �� ���������� ����
// ������ � �� ���� ����� (������ ������ �� ������� � �����) �� �����.
// �����: ������� �� ������� � ������ ������ �� �������, �� ���� �� ���.
// ���������.  ������ �� ��������� ���� ��������� �� �����.  ������������
// �������� ����, �� ����������� (set) � STL �� ��������� �� ��� �� ����������
// �� ��������� ��, �� ������ ����� �� ������� �������� ����� ��� � � ����
// ���������� �� ����-���� ����� ����� ������, ��� ������� ���������� ���
// �������

#include <iostream>
#include <vector>
#include <set>
using namespace std;
// ����� �� ����: ������ �� ���������-������ � �����
struct edge {int u,v; int wt;};
// ���������� ������� �� ���������� �� ������� ���� �������� �� ���������
struct setcmp {
  bool operator()(const edge a, const edge b) const  {
    return a.wt<b.wt;
  }
};
// ����: ��������� �� �����, ���������� ��� setcmp �� ��-����
typedef multiset<edge,setcmp> edges;

// �������� �� ����������� �����: tree[i] � ������� �� �������� �� ����� � �-� i
void findmintree(edges & es, vector<int> & tree)  {
  set<int> ns;      // �����: ��������� �� ������
  int nv = tree.size();
// �������� ������� � ����� ������ ��������� ������ nv �� ����
  for (ns.insert(1),tree[0]=0; ns.size()<nv;)
// �������� ������� �����, ����� ������ �� ������� � ��������� � ������� �������
    for (edges::const_iterator p=es.begin();; ++p)  {
      int a = p->u,  b = p->v;
#define chosen(n) (ns.find(n)!=ns.end())
      if (chosen(b))  swap(a,b);
      if (chosen(a) && !chosen(b))  {
        ns.insert(b);
        tree[b-1] = a-1;
        es.erase(p);
        break;
      }
    }
}

int main()  {
  edges es;
  edge e;
  int nv, ne;
  cin >> nv >> ne;    // ������ �� ���� ������� � �����
  vector<int> tree(nv);
  while (ne--)  {     // ������ �� ����� � ��������� � �����
    cin >> e.u >> e.v >> e.wt;
    es.insert(e);
  }
  findmintree(es,tree);  // �������� �� �������
  for (int i=1; i<nv; ++i)
    cout << 1+tree[i] << ' ' << 1+i << endl;
  return 0;
}
