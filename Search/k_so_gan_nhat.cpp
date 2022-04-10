#include <iostream>
#include <math.h>


using namespace std ;

int Binary_search ( int *a, int x, int n )
{
    int head = 0;
    int tail = n-1 ;
    int mid, val1, val2 ;
    while ( head <= tail ) 
    {
        val1 = abs ( x - a[mid] ) ;
        val2 = abs ( x - a[mid + 1 ] ) ;
        mid = ( head + tail ) / 2 ;
        if ( val1 > val2 ) 
        {
            
        }
        else if ( a[mid] > x || a[mid -1] == x )
        {
            tail = mid - 1 ;
        }
        else 
        {
            head = mid + 1 ;
        }
    }
    return pos ;
}

int main() 
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n, m, *a, *b, pos , x;
    
    
    cin >> n ;
    a = new int[n] ;
    for ( int i = 0 ; i < n ; i ++ ) 
    {
        cin >> a[i] ;
    }
    cin >> m ;
    b = new int[m] ;
    for ( int i = 0 ; i < m ; i++ ) 
    {
        cin >> b[i] ;
    }
    
    for ( int i = 0 ; i < m ; i++ ) 
    {
        if ( n == 0 ) cout << -1 << "\n" ;
        x = b[i] ;
        cout << Binary_search ( a, x, n ) << "\n" ;   
    }
    return 0 ;
}