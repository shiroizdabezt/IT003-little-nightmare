#include <iostream>

using namespace std ;

int Binary_search ( int *a, int x, int n )
{
    int head = 0;
    int tail = n-1 ;
    int mid, pos = -1 ;
    /* while ( head <= tail ) 
    {
        mid = ( head + tail ) / 2 ;
        if ( a[mid] == x && mid < n && a[mid + 1 ] != x ) 
        {
            return mid ;
        }
        else if ( a[mid] == x && mid >= n - 1 )
            return mid ;
        else if ( a[mid] == x && mid < n && a[mid + 1] == x )
            head = mid + 1 ;
        else if ( a[mid] > x || a[mid -1] == x )
        {
            tail = mid - 1 ;
        }
        else 
        {
            head = mid + 1 ;
        }
    } */
    while ( head <= tail ) 
    {
        mid = ( head + tail ) / 2 ;
        if ( ( mid == 0 || a[mid-1] < x) && ( a[mid] == x ) )
        {
            pos = mid ;
            tail = mid - 1;
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