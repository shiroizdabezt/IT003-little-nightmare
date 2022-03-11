#include <iostream>

using namespace std ;

int main()
{
    int x, y, n, m, hit = 0 ;
    cin >> x >> y >> n >> m ;
    for ( int i = 0 ; i < n ; i++ )
        {
            if ( m % x == 0 ) 
                hit += m / x ;
            else 
                hit += (m / x) + 1 ;
            x += y ;
        }
    cout << hit ;
    return 0 ;
}