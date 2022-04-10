/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
cout
cin
printf
###End banned keyword*/

#include <iostream>
#include <algorithm>

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
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


//###INSERT CODE HERE -

List* merge_2_sorted_lists ( List l1, List l2)
{
    Node *p = l1.head ;
    Node *q = l2.head ;
    List l3 ;
    initializer_list ( l3 ) ;
    Node *t = r ;
    while ( p != NULL && q != NULL )
    {
        if ( p->val < q->val )
        {
            t->next = p ;
            p = p->next ;
        }
        else 
        {
            t->next = q ;
            q = q->next ;
        }
        t = t->next ;
    }
    while ( p != NULL )
    {
        t->next = p ;
        p = p->next ;
        t = t->next ;
    }
    while ( q != NULL )
    {
        t->next = q ;
        q = q->next ;
        t = t->next ;
    }
    
}


int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for(int i = 0; i < 2; i++){
        list_initializing(lists[i]);
        int x;
        do{
            cin >> x;
            if (x != 0) add_tail(lists[i], x);
            else break;
        } while(true);
    }

    List l = merge_2_sorted_lists(lists[0], lists[1]);

    xuat(l);

    return 0;
}
