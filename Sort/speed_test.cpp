/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
std
###End banned keyword*
//* void Shell_sort ( int *a, int n ) 
{
    for ( int i = n/2; i > 0 ; i = i/2 ) 
    [
        for ( int j = i ; j < n ; j++ ) 
        {
            int x = a[i] ;
            int y ;
            for ( y = j ; y >= gap && a[y - i] > x; y -= i ) 
                a[y] = a[y-i] ;
            a[y] = x ;
        }
    ]
} */

#include <iostream>
#include <chrono>
#include <utility> 
#include <ctime>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     std::ios_base::sync_with_stdio(false)

//###INSERT CODE HERE -
void swap ( auto &a, auto &b ) 
{
    auto t = a;
    a = b ;
    b = t ;
}
void insertion_Sort ( int *a, int n ) 
{
    int temp, j;
    for ( int i = 1; i < n ; i++ ) 
    {
        temp = a[i] ;
        j = i - 1 ;
        while ( j >= 0 && a[j] > temp )
        {
            a[j+1] = a[j] ;
            j = j- 1 ;
        }
        a[j+1] = temp ;
    }
}


void Shell_Sort ( int *a, int n )
{
    for ( int gap = n/2 ; gap > 0 ; gap /= 2 )
    {
        for ( int i = gap ; i < n ; i++ )
        {
            int x = a[i] ;
            int j ; 
            for ( j = i ; j >= gap && a[j-gap] > x ; j -= gap ) 
                a[j] = a[j-gap] ;
            a[j] = x ;
        }
    }
}

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

void quick_sort ( int *a, int low, int high)
{
    if ( low >= high ) return; 
    int i = low , j = high - 1, pivot = a[high] ; 
    while ( 1 ) 
    {
        while ( a[i] < pivot ) i++ ;
        while ( a[j] > pivot ) j-- ;
        if ( i >= j ) break; 
            swap(a[i], a[j]);
            i++; j--; 
    }
    swap(a[high], a[i]) ;
    quick_sort ( a, low, i-1 );
    quick_sort ( a, i+1, high ) ;
} 

void heapify(int *a, int k, int n) // == down heap
{
    int j = 2*k+1 ;
    while (j<n) 
    {
        if (j+1<n) 
        {
            if ( a[j] < a[j+1] ) 
            {
                j = j+1 ;
            }
        }
        if ( a[j] <= a[k] ) return ;
        swap ( a[k], a[j] ) ;
        k = j ;
        j = 2*k+1 ;
    }
}

void build_heap( int *a, int n )
{
    int i = (n-1)/2 ;
    while ( i>= 0 ) 
    {
        heapify ( a, i, n) ;
        i = i-1 ;
    }
}

void heap_sort(int *a, int n) 
{
    build_heap(a, n) ;
    while ( n>0 ) 
    {
        n = n-1;
        swap(a[0], a[n]) ;
        heapify(a, 0, n) ;
    }
}

int main() 
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    long long n;
    srand(time(0));
    n = 512000000;
    int *a = new int [n] ;
    for ( int i = 0 ; i < n ; i++ )
        a[i] = rand() ;
    auto start = std::chrono::steady_clock::now();
    heap_sort ( a, n ) ;
    //partition ( a, 0, n ) ;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0 ;
}