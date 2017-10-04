// Намиране на минимално скелетно дърво на претеглен граф по алгоритъма на Прим.
// Вход: един ред с <брой-върхове> <брой-ребра>, следван от съответния брой
// редове с по едно ребро (двойка номера на върхове и тегло) на всеки.
// Изход: ребрата на дървото – двойки номера на върхове, по една на ред.
// Забележка.  Графът се представя като множество от ребра.  Реализацията
// използва това, че множествата (set) в STL се изброяват по ред на нарастване
// на членовете им, от гледна точка на някаква подредба между тях – с това
// избирането на „най-леко“ ребро става удобно, без изрично подреждане или
// търсене

#include <iostream>
#include <vector>
#include <set>
using namespace std;
// ребро на граф: номера на върховете-краища и тегло
struct edge {int u,v; int wt;};
// сравняваща функция за подреждане на ребрата като елементи на множество
struct setcmp {
  bool operator()(const edge a, const edge b) const  {
    return a.wt<b.wt;
  }
};
// граф: множество от ребра, подреждани със setcmp от по-горе
typedef multiset<edge,setcmp> edges;

// намиране на минималното дърво: tree[i] е номерът на родителя на върха с н-р i
void findmintree(edges & es, vector<int> & tree)  {
  set<int> ns;      // възли: множество от номера
  int nv = tree.size();
// добавяме върхове и ребра докато върховете станат nv на брой
  for (ns.insert(1),tree[0]=0; ns.size()<nv;)
// намираме първото ребро, чиито краища са включен и невключен в дървото върхове
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
  cin >> nv >> ne;    // четене на брой върхове и ребра
  vector<int> tree(nv);
  while (ne--)  {     // четене на ребра и поставяне в графа
    cin >> e.u >> e.v >> e.wt;
    es.insert(e);
  }
  findmintree(es,tree);  // намиране на дървото
  for (int i=1; i<nv; ++i)
    cout << 1+tree[i] << ' ' << 1+i << endl;
  return 0;
}
