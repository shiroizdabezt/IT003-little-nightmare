/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct node 
{
    int value ;
    node* next ;
};

struct list 
{
    node *head ;
    node *tail ;
};
void  initialize_list( list &a)
{
    a.head = NULL;
    a.tail = NULL;
}
node* CreateNode( int x)
{
    node* p ;
    p = new node;
    p->value = x;
    p->next = NULL;
    return p;
}
void add_front( list &a, int b)
{
    node* C;
    C = CreateNode(b);
    if ( a.head == NULL )
        {
            a.head = C ;
            a.tail = C ;
        }
    else
        {
            C->next = a.head ;
            a.head = C ;
        }
}
void add_back( list &a, int b)
{
    node* C;
    C = CreateNode(b);
      if ( a.head == nullptr) 
        {
            a.head = C ;
            a.tail = C ;
        }
    else 
        {
            a.tail->next = C ;
            C->next = NULL;
            a.tail = C ;
        }
}
void Add_after( list &a , node* p, node* q)
{
    if( q == a.tail )
    {
        a.tail->next = p;
        a.tail = p;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}
//////////
int main()
{
    list a;
    initialize_list(a);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int x, b, c;
    do {
        cin >> x;
        switch (x){
        case 0:
            cin >> b;
            add_front(a, b);
            break;
        case 1:
            cin >> b;
            add_back(a, b);
            break;
        case 2:
            cin >> b >> c;
            node* C ;
            C = CreateNode(c);

           node* pos  = NULL;
             for (node* it = a.head; it ; it = it->next){
                    if ( it->value == b )
                    {
                        pos = it ;
                        break;
                    }
             }
             if( pos == NULL )  add_front(a, c);
            /* else if ( pos != a.head ) AddAt( a, A , pos );
            else if ( pos ==  a.head ) AddAt(a, A , a.head ); */
            else if ( pos != NULL ) Add_after( a, C , pos );
            break;
        }
    } while (x != 3);

    for (node* it = a.head; it ; it = it->next){
        cout << it->value << " ";
    }
    return 0;
}


