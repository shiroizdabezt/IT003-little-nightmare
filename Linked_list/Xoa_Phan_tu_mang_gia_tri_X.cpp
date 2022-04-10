/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using  std::cin;
using  std::cout;
using  std::endl;
using std::ios_base;

//###INSERT CODE HERE -
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

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
void delete_after_p ( list &l , node* p ) 
{
    if ( p->next == l.tail ) // Node muốn xóa nằm đằng sau node p và nó là node cuối cùng của danh sách
    {
        delete l.tail ;
        l.tail = p ;
        l.tail->next = NULL ;
    }
    else 
    {
        auto q = p->next ; // q là node muốn xóa
        p->next = q->next ;
        delete q ;
    }
}

//////////
int main()
{
    list a;
    initialize_list(a);
    int x, b, c;
    int flag = 0 ;
    do {
        cin >> x;
        switch (x)
        {
        case 0:
            cin >> b;
            add_front(a, b);
            break;
        case 1:
            cin >> b;
            add_back(a, b);
            break;
        case 2:
            {
            cin >> b >> c;
            node* C ;
            C = CreateNode(c);

           node* pos  = NULL;
             for (node* it = a.head; it ; it = it->next)
             {
                    if ( it->value == b )
                    {
                        pos = it ;
                        break;
                    }
             }
             if( pos == NULL )  add_front(a, c);
            else if ( pos != NULL ) Add_after( a, C , pos );
            break;
            }
        case 3: 
            {
            cin >> b ;
            //Gồm có các trường hợp :
                if ( a.head == NULL) 
                {
                }
                else if ( a.head->value == b  ) 
                {
                    delete_head (a) ;
                }
                else 
                {
                    //cần tìm node đứng trước node đầu tiên mang giá trị n
                    auto p = a.head ;
                    /* while ( p->next->value == n ) 
                    {

                    } */
                    while ( p != NULL ) 
                    {
                        if ( p->next == NULL ) 
                        {
                            flag = 0 ;
                            break; 
                        } 
                        else if ( p->next->value == b ) 
                        {
                            flag = 1 ;
                            break;
                        }
                        p = p->next ;
                    }
                    if ( flag == 1 ) 
                    {
                        delete_after_p ( a, p ) ;
                    }
                }
            }
            break; 
        case 4:
        {
            cin >> b ;
            if ( a.head == NULL) 
                {

                }
            else if ( a.head->value == b  ) 
                {
                    delete_head (a) ;
                }
            auto p = a.head ;
            while ( p != NULL ) 
            {
                if ( p->next == NULL ) 
                {
                    break; 
                }
                else if ( p->next->value == b ) 
                {
                    delete_after_p ( a, p ) ; 
                }
                else
                    p = p->next ;
            }
            break;
        }
        case 5:
            {
                delete_head ( a ) ;
                break; 
            }
        }
    }
    while (x != 6);
    for (node* it = a.head; it ; it = it->next){
        cout << it->value << " ";
    }
    return 0;
}


