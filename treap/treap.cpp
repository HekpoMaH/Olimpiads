#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
struct treap
{
    int x, value, maxValue;
    double y;
    treap *l, *r;
    treap(int x, int value): x(x), y(rand()), value(value), maxValue(value), l(NULL), r(NULL) {}
    treap():l(NULL), r(NULL){}
    void Recalc()
    {
        if (!this)return;
        this->maxValue = this->value;
        if(this->l && this->l->maxValue > this->maxValue)this->maxValue = this->l->maxValue;
        if(this->r && this->r->maxValue > this->maxValue)this->maxValue = this->r->maxValue;
    }
};
void split(treap * t,int x,treap* &l,treap* &r)
{
    if (!t)
    {
        l = NULL;
        r = NULL;
        return;
    }
    if (t->x > x)
    {
        r = t;
        split(r->l, x, l, r->l);
    }
    else
    {
        l = t;
        split(l->r, x, l->r, r);
    }
    r->Recalc();
    l->Recalc();
}
void merge(treap* l, treap* r, treap* &t)
{
    if (!l || !r)
    {
        t = !l ? r : l;
        return;
    }
    if (l->y > r->y)
    {
        t = l;
        merge(l->r, r, l->r);
    }
    else
    {
        t = r;
        merge(l, r->l, r->l);
    }
    t->Recalc();
}
int max(int x, int y, treap* t)
{
    treap *l = new treap(), *m = new treap(), *r = new treap();
    split(t, x - 1, l, r);
    split(r, y, m, r);
    int result = m->maxValue;
    merge(l, m, l);
    merge(m, r, t);
    return result;
}
void insert(int x, int value, treap* &t)
{
    if (!t)
    {
        t = new treap(x, value);
        return;
    }
    treap *l = new treap(), *m = new treap(x, value), *r = new treap();
    split(t, x, l, r);
    merge(l, m, m);
    merge(m, r, t);
}
int main()
{
    srand((int)time(0));
    treap* t = NULL;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, v;
        cin >> x >> v;
        insert(x, v, t);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << max(x, y, t) << endl;
    }
    return 0;
}
