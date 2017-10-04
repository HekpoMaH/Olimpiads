#include<iostream>
using namespace std;
struct tree// structurata na samoto dyrvo
{
    int key;// informacionno pole
    tree *left,*right;// ukazateli kym leviq i desniq naslednik
}*t;

void addNode(int x,tree*&t)// za dobavqne na vryh
{
    if(t==NULL)// ako sme namerili mqstoto na koeto trqbva da stoi noviqt vryh
    {
        t=new tree;// syzdavame noviq vryh
        t-> key=x;// zadavame informacionnoto mu pole
        t-> left=NULL;// i zanulqvame naslednicite mu
        t->right=NULL;// -||-
    }
    /*
    Ako vse o6te ne sme otkrli
    mqstoto na noviq vryh
    */

    else if(x<t->key) addNode(x,t->left);// proverqvame ako e po-malyk ot teku6tiq otivame v lqvoto poddyrvo

    else if(x>t->key) addNode(x,t->right);// ako e po-golqm otivame v dqsnoto poddyrvo

    else cout<<"tozi element go ima"<< " "<<endl;/* ako e raven to togava znachi sy6testvuva
                                                     v dyrvoto i  ne go dobavqme
                                                     */


}
void create(tree*& t)// funkciq za syzdavane na dyrvoto
{
    t=NULL;
    int x;

    while (cin>>x)addNode(x,t);// dokato se vyvejdat novi vyrhove gi dobavqme v dyrvoto
}

void print_lkd(tree*&t)// za obhojdane lqvo koren dqsno
{
    if(t!=NULL)// ako vse o6te ne sme dostignali kraq na poddyrvoto i sme o6te v sytestvuvasht vryh
    {
        print_lkd(t->left);// otivame v lqvoto poddyrvo

        cout<<t->key<<" ";//otpe4atvame nomera na teku6tiq vryh

        print_lkd(t->right);// i otivame v dqsnoto poddyrvo
    }
}

void PrintTree(tree * t ,int h)// za otpe4atvane na dyrvoto
{
    if(t!=NULL)// ako vse o6te ne sme dostignali kraq na poddyrvoto i sme o6te v sytestvuvasht vryh
    {
        PrintTree(t->right,h+1);// otivame v dqsnoto poddyrvo

        for(int i=0;i<h;i++) cout<<" ";// otpe4atvame h na broi intervali zada se polu4i kato dyrvo

        cout<<t->key<<endl;// otpe4atvame nomera na teku6tiq vryh

        PrintTree(t->left,h+1);// i otivame v lqvoto poddyrvo
    }
}
/*
sledva6tite dve funkcii sa ot tip int
tova zna4i 4e te 6te vyrnat rezultat na main() funkciqta i returna trqbva da e ot sy6tiq tip
tipa e int za6toto i sumata i tegloto sa celi 4isla

gornite funkcii sa void za6toto te ne vry6tat na main() rezultat a imat samo deistvie
*/

int teglo(tree * t)// za tegloto na dyrvoto
{
    int br;// v neq 6te natrupvame tegloto

    if(t!=NULL) br=1+teglo(t->left)+teglo(t->right);
    /*
        ako sme v sytestvuva6t vryh to negovot teglo e 1 + tegloto na lqvoto i na dqsnoto poddyrvo
        zatova rekursivno vikame teglo(t->left)+teglo(t->right)
    */
    else br=0;

    /*
        no ako ve4e sme dostignali do mometn v koito nqma sytestvuva6t vryh
        to togava negovoto teglo e 0 za6toto kogato nqma vryh nqma i teglo
    */


    return br;// vry6tame namerenoto teglo
}

int suma(tree * t )// za sumata ot vyrhovrte
{
    int sum ;// v neq 6te natrupvame sumata

    if(t!=NULL) sum=t->key+suma(t->left)+suma(t->right);

    /*
        ako sme v sytestvuva6t vryh to negovata suma e nomeryt mu + sumata na lqvoto i na dqsnoto poddyrvo
        zatova rekursivno vikame suma(t->left)+suma(t->right)
    */

    else sum=0;

    /*
        no ako ve4e sme dostignali do mometn v koito nqma sytestvuva6t vryh
        to togava negovata suma e 0 za6toto kogato nqma vryh nqma i suma
    */

  return sum;// vry6tame namerenoto teglo
}
void printdkl(tree *t)
{
  if(t!=NULL)
  {
    printdkl(t->right);
    cout<<t->key<<endl;
    printdkl(t->left);
  }
}
int lista(tree *t)
{
  if(t)
  {
  if(t->left==NULL&&t->right==NULL)return 1;
  else return lista(t->left)+lista(t->right);
  }
  else return 0;
  //return br;
}
int dept(tree *t)
{
  if(t)
  {
    int k=dept(t->left);
    int m=dept(t->right);
    if(k<m)k=m;
    return k+1;
  }
  else return 0;
}
int main()
{
    create(t);// vikame funnkciqta za syzdavane na dyrvoto

    print_lkd(t);// obhojdame go LKD
    cout<<endl;// za nov red
    printdkl(t);

    PrintTree(t,0);// otpe4atvame dyrvoto

    cout<<"tegloto e :"<<teglo(t)<<endl;// otpe4atvame tegloto
    cout<<"sumata e " <<suma(t)<<endl;// otpe4atvame sumata
    cout<<"listata sa:"<<lista(t)<<endl;
    cout<<"dalbo4inata e:"<<dept(t)<<endl;
    return 0;
}
