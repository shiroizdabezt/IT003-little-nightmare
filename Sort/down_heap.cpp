#include <iostream>

using namespace std ;

void swap ( auto &a, auto &b ) 
{
    auto t = a;
    a = b ;
    b = t ;
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
    int n, m, count = 0, j, num;
    cin >> n >> m;
    int *a = new int[n] ;
    for ( int i = 0 ; i < n ; i++ ) 
        cin >> a[i] ;
    //heap_sort(a, n) ;
    build_heap(a, n);
    while ( count < m )
    {
        count++;
        cin >> j ;
        if ( n == 0 ) 
        {
            m = 0 ;
            break;
        }
        switch (j)
        {
            case -1:
                //n = n-1;
                a[0] = a[--n] ;
                heapify(a,0 , n) ;
                if ( n == 0 ) 
                {
                    m = 0 ;
                    break;
                }
                break;
            case -2:
            {
                int max = a[0] ;
                while (a[0] == max) 
                {
                    a[0] = a[--n] ;
                    heapify(a, 0, n) ;
                    if ( n == 0 ) 
                    {
                        m = 0 ;
                        break;
                    }
                }
                break;
            }
            case -3:
            {
                cin >> num;
                a[0] -= num ;
                heapify(a, 0, n) ;
                break;
            }
            case -4:
            {
                cin >> num;
                int max = a[0];
                while (max == a[0])
                {
                    a[0] -= num ;
                    heapify(a, 0, n) ;
                }
                break;
            }
        }

    }
    heap_sort(a, n) ;
    for ( int i = n-1 ; i >= 0 ; i-- ) 
        cout << a[i] << "\n";
    return 0;
}