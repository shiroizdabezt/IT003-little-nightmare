#include <iostream>

using namespace std ;

int main()
{
    int a[1000000], n, count = 0;
    cin >> n ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> a[i] ;
    for ( int i = 0 ; i < n/2 ; i++ )
        {
            if ( a[i] != a[ n - 1 - i ] ) 
                count++ ;
        }
    if ( count > 1 ) 
        cout << "FALSE" ;
    else 
        cout << "TRUE" ;
    return 0;
}