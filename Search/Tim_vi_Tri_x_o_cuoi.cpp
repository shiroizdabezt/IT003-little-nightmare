#include <iostream>

using namespace std ;

int Binary_search ( int *a, int x, int n )
{
    int head = 0;
    int tail = n-1 ;
    int mid ;
    while ( head <= tail ) 
    {
        mid = ( head + tail ) / 2 ;
        if ( a[mid] == x && mid < n && a[mid + 1 ] != x ) 
        {
            return mid ;
        }
        else if ( a[mid] == x && mid >= n - 1 )
            return n -1 ;
        else if ( a[mid] == x && mid < n && a[mid + 1] == x )
            head = mid + 1 ;
        else if ( a[mid] > x )
        {
            tail = mid - 1 ;
        }
        else 
        {
            head = mid + 1 ;
        }
    }
    return -1 ;
}

int main() 
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n, m, *a, *b, pos , x;
    a = new int[n] ;
    
    cin >> n ;
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
    if ( n == 0 ) cout << -1 << "\n" ;
    for ( int i = 0 ; i < m ; i++ ) 
    {
        
        x = b[i] ;
        cout << Binary_search ( a, x, n ) << "\n" ;   
    }
    return 0 ;
}