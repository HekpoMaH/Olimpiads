//http://www.math.bas.bg/~nkirov/book2/l25.html - преработена
#include <iostream> 
#include <cstring>
using namespace std; 
char text[] = "abracadabra"; 
char code[256]; 
int text_len; 
struct Huf { 
   char id; 
   int wh; 
   Huf *left, *right; 
}; 
struct List { 
   List *next; 
   Huf *tree; 
}; 
List *head; 

void createList() 
{ int i; 
  int ch[256] = {0}; 
  for (i=0; i<text_len; i++) ch[text[i]]++; 
  List *l; 
  Huf *h; 
  head = 0; 
  for (i=0; i<255; i++) if (ch[i]>0) 
  { h = new Huf; 
    h->id = i; h->wh = ch[i]; 
    h->left = 0; h->right = 0; 
    l = new List; 
    l->tree = h; 
    l->next = head; head = l; 
  } 
} 
void writeList() 
{ cout << "writeList\n"; 
  List *l = head; 
  while (l) 
  { cout << (l->tree)->id << " "; 
    l = l->next; 
  } 
  cout << endl; 
  l = head; 
  while (l) 
  { cout << (l->tree)->wh << " "; 
    l = l->next; 
  } 
  cout << endl; 
} 
void delList(List *l) 
{ List *lp, *lc; 
  if (l==head) { head=l->next; delete l; } 
  else 
  { lp = head; lc = lp->next; 
   while (lc!=l) { lp = lc; lc = lc->next; } 
   lp->next = lc->next; delete lc; 
  } 
} 
void addList(Huf *h) 
{ List *l = new List; 
  l->tree = h; 
  l->next = head; 
  head = l; 
} 
Huf *findDels() 
{ List *l = head, *sm = head; 
  Huf *h; 
  while (l) 
  { if ((l->tree)->wh < (sm->tree)->wh) sm = l; 
   l = l->next; 
  } 
  h = sm->tree; 
  delList(sm); 
  return h; 
} 
void createTree() 
{ Huf *h, *h1, *h2; 
  while (head->next) 
  { h1 = findDels(); 
    h2 = findDels(); 
    h = new Huf; 
    h->id = ' '; h->wh = h1->wh + h2->wh; 
    h->left = h1; h->right = h2; 
    addList(h); 
  } 
} 
void rlrootTree(Huf *h, unsigned index) 
{ if (h) 
  { code[index] = '0'; 
    rlrootTree(h->right, index+1); 
    if (h->left == 0) 
    { code[index] = '\0'; 
      cout << h->id << "->" << code << " "; 
    } 
    code[index] = '1'; 
    rlrootTree(h->left, index+1); 
  } 
} 

int main() 
{ text_len = strlen(text); 
  createList(); 
  writeList(); 
  createTree(); 
  cout << "writeCodes - reverse order\n"; 
  rlrootTree(head->tree, 0); 
  cout << endl; 
  return 0; 
} 