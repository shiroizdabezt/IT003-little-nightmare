/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using  std::cin;
using  std::cout;
using  std::endl;


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

void initialize_list ( list &a ) 
{
    a.head = NULL ;
    a.tail = NULL ;
}

void add_front ( list &a , int b ) 
{
    node* C = new node;
    C->value = b;
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

void add_back ( list &a , int b )
{
    node* C = new node;
    C->value = b;
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
        }
    } while (x != 3);

    for (node* it = a.head; it ; it = it->next){
        cout << it->value << " ";
    }
    return 0;
}
