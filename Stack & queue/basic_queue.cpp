/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

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

void delete_head ( list &l ) 
{
    if ( l.head == NULL ) 
    {
        return ;
    }
    else if ( l.head == l.tail ) 
    {
        delete l.head ;
        l.head = l.tail = NULL ;
    }
    else 
    {
        auto p = l.head ;
        l.head = l.head->next ;
        delete p ;
    }
}

bool isEmpty ( list &a)
{
    return (a.head == 0 ) ;
}

void pop ( list &a )
{
    if ( a.head == NULL ) 
    {
        std::cout << "EMPTY\n" ;
        return;
    }
    else 
    {
        std::cout << a.head->value << "\n" ;
        delete_head( a ) ;
        return;
    }
} 

void top ( list &a )
{
    ( a.head == NULL ) ? std::cout << "EMPTY\n" : std::cout << a.head->value << "\n" ; 
}

int main() 
{
    list a ;
    initialize_list ( a ) ;
    int x, n ;
    do
    {
        std::cin >> x ;
        switch (x)
        {
        case 1:
            {
                std::cin >> n ;
                add_back ( a, n ) ;
                /* std::cout << "pushed" ;
                std::cout << "\nSTACK: ";
                for (node* it = a.head; it ; it = it->next)
                {
                    std::cout << it->value << " ";
                }
                std::cout << "\n" ; */
                break;
            }
        case 2:
            {
                pop(a) ;
                /* std::cout << "STACK: ";
                for (node* it = a.head; it ; it = it->next)
                {
                    std::cout << it->value << " ";
                }
                std::cout << "\n" ; */
                break;
            }
        case 3: 
            {
                top ( a ) ;
                /* std::cout << "STACK: ";
                for (node *it = a.head; it ; it = it->next)
                {
                    std::cout << it->value << " ";
                }
                std::cout << "\n" ; */
                break;
            }
        }
    } while (x != 4 );
    return 0 ;
}