/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}

//###INSERT CODE HERE -
Node* CreateNode( int x)
{
    Node* p ;
    p = new Node;
    p->val = x;
    p->next = NULL;
    return p;
}

void add_tail( List &a, int b)
{
    Node* C;
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

void copy ( List l, List &l2 ) 
{
    Node *p =new Node ;
    p->val = l.head->val ;
    Node *q = p ;
    l2.head = q ;
    l.head = l.head->next ;
    for ( l.head; l.head != NULL ; l.head = l.head->next , q = q->next ) 
    {
        p = new Node ;
        p->val = l.head->val ;
        q->next = p ;
    }
    l.tail = p ;
    p->next = NULL ;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.head, *q = l2.head;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    return 0;
}
