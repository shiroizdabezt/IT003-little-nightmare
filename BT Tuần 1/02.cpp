#include <iostream>

using namespace std ;

typedef struct PHANSO
{
    int ts, ms;
}PS;


int main()
{
    PS ps[100000] ;
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i++)
        cin >> ps[i].ts >> ps[i].ms ;
    for ( int i = n-1 ; i >= 0 ; i-- )
        cout << ps[i].ts << "/" << ps[i].ms << "\n" ;
    return 0 ; 
}