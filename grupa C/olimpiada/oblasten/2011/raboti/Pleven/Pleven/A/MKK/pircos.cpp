#include<cstdio>
#include<vector>
#include<algorithm>
#define PB push_back
using namespace std;



struct node
{
    char d;
    node* prev;
    vector<node*> to;
    node (char _d)
    {
        d = _d;
        prev = NULL;
    }

};




node root = node('*');
vector<long long> v;




main ()
{
    int N;
    scanf("%d",&N);

    for ( int i = 0; i < N; i ++)
    {
        long long inp;
        scanf("%lld",&inp);
        inp*=10;
        inp+=1;
        long long number = 0;
        while(inp!=0)
        {
            number*= 10;
            number += inp%10;
            inp/=10;
        }

        //we check if the number exists in the tree
        bool ok = true; //have we got a match
        inp = number;
        node* current = &root;
        node* lastOne;
        while ( number!=0)
        {
            char c = number%10 + 48;
            if (number < 10 ) c = '*';
            number /= 10;
            short s = (*current).to.size();
            bool foundit = false;
            short dd;
            for ( short i = 0; i < s; i ++)
            {
                node* n = current->to[i];
                if ( n->d == c )
                {
                    foundit = true;
                    dd = i;
                    break;
                }
            }

            if ( foundit )
            {
                current = current->to[dd];
                lastOne = current;
            }
            else
            {
                ok = false;
                break;
            }
           // if ( number < 10 )
           // {
           //     lastOne = current->to[0];
           //     number/=10;
           // }

        }
        //end of check

        //printf("checkcompleted\n");

        if ( ok ) // must be erased!
        {
           // printf("Erase\n");
            current = lastOne->prev;
            while(1)
            {
               // printf("lastOne:%c\n",(*lastOne).d);
              //  printf("current:%c\n",(*current).d);
                short s = (*current).to.size();
                for ( vector<node*>::iterator i = (*current).to.begin(); i != (*current).to.end(); i ++)
                 {
                     node* n = *i;
                     if ( n == lastOne)
                     {
                         (current->to).erase(i);
                         delete lastOne;
                         lastOne = current;
                         current = lastOne->prev;
                         break;
                     }
                 }

                //printf("lastOne:%c\n",lastOne->d);
                if ( (*lastOne).to.size() > 0 || lastOne == &root)

                 break;
            }
        }
        else // if it doesn't exist in the current contest, it must be added
        {
            number = inp;

           // printf("ADD:\nnumber:%d\n",number);
            current = &root;
            while(number!= 0)
            {

                char c = number%10 + 48;
                if ( number < 10 )
                 {
                     c = '*';
                     node* newone = new node(c);
                     newone->prev = current;
                    (*current).to.PB(newone);
                    break;
                 }
                number/=10;

                bool foundit = false;
                short where;
                short s = (*current).to.size();


                for ( short i = 0; i < s; i ++)
                {
                    node* n = current->to[i];
                    if ( n->d == c)
                    {
                        foundit = true;
                        where = i;
                        break;
                    }
                }

                if ( foundit )
                {
                   // printf("found:%d\n",(*current).d-48);
                    current = current->to[where];

                }
                else
                {
                   // printf("added:%d\n",c-48);
                    node* newone = new node(c);
                    newone->prev = current;
                    (*current).to.PB(newone);
                    current = newone;
                }

            }


        }
    }




    while ( 1 )
    {
        node* current = &root;
        node* lastOne = current;
        short apf = root.to.size();
      //  printf("%d\n",apf);
        if ( apf < 1 )
            break;
        long long otg = 0;


      //  printf("marker\n");
        while (1)
        {

            if ( (*current).to.size() == 0 ) break;
            current = (*current).to[0];

            if ( (*current).d == '*') { lastOne = current; break;}
            otg *= 10;
            otg += ((*current).d - 48);
            //printf("current.d: %c", (*current).d);
            lastOne = current;
        }

        v.PB(otg);

        //the erasing part
        current = lastOne->prev;
            while(1)
            {
                for ( vector<node*>::iterator i = (*current).to.begin(); i != (*current).to.end(); i ++)
                 {
                     node* n = *i;
                     if ( n == lastOne)
                     {
                         ((*current).to).erase(i);
                         delete lastOne;
                         lastOne = current;
                         current = lastOne->prev;
                         break;
                     }
                 }

                if ( (*lastOne).to.size() > 0 || lastOne == &root)
                 break;
            }

    }

    sort(v.begin(),v.end());
    short iee = v.size()-1;
    for ( short i = 0; i <iee; i ++)
     {
         printf("%lld ",v[i]);
     }
    printf("%lld\n",v[iee]);

    return 0;
}
