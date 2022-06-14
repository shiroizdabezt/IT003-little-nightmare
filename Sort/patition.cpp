/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
new
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;


//###INSERT CODE HERE -
int partition ( int pivot, int *a, int n ) 
{
    pivot = a[n-1] ;
    int i = -1 ; 
    /* while ( i < j ) 
    {
        while ( a[i] < pivot ) i++ ;
        while ( a[j] > pivot ) j-- ;
        if ( i >= j ) break; 
            int temp = a[i] ;
            a[i] = a[j] ;
            a[j] = temp ; 
            i++; j--; 
    } */
    for ( int j = 0 ; j < n-1 ; j++ ) 
    {
        if ( a[j] < pivot ) 
            {
                i += 1 ; 
                int temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp ;
            }
    }
    int temp = a[i+1] ;
    a[i+1] = a[n-1] ;
    a[n-1] = temp ;
    return i+1;
}


int main()
{
    int n, pivot;
    cin >> n ;
    int * a = new int [n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int p = partition(pivot, a, n);
    for (int i = 0; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << p;
}
