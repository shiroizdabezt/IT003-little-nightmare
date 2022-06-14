/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
using namespace std;


//###INSERT CODE HERE -

void merge( int *a, int n, int *b, int m, int *c)
{
    int i = 0, j = 0, k = 0 ;
    while ( i < n && j < m ) 
    {
        if ( a[i] < b[j] )
            {
                c[k] = a[i] ;
                i++ ; k++ ;
            }
        else    
            {
                c[k] = b[j] ;
                j++ ;k++ ;
            }
    }
    while ( i < n ) 
    {
        c[k] = a[i] ;
        k++; i++ ;
    }
    while ( j < m ) 
    {
        c[k] = b[j] ;
        k++; j++ ;
    }
}

void its_magic ( int *a, int n, int k, int *temp ) 
{
    for ( int i = 0 ; i < n ; i += 2*k ) 
    {
        auto min = [](auto a, auto&& b) { return a < b? a : b; };
        merge ( a+i, min ( n-i, k), a+i+k, min (n-i-k, k), temp+i ) ;
    }
}

void ms ( int * &a, int n ) 
{
    int *temp = new int [n] ;
    for ( int k = 1; k <= n; k*=2 ) 
    {
        its_magic ( a, n, k, temp ) ;
        swap (a, temp ) ;
    } 
}
int main () {
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    int *temp = new int [n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int i = 0;
    
    its_magic(a, n, k, temp);

    for(int i = 0; i < n; i++){
        cout << temp[i] << " ";
    }
}


