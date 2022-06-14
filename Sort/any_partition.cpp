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
#define fast_io     std::ios_base::sync_with_stdio(false)


//###INSERT CODE HERE -
int partition ( int pivot, int *a, int n ) 
{
    int i = 0 , j = n-1 ; 
    while ( i < j ) 
    {
        while ( a[i] < pivot ) i++ ;
        while ( a[j] > pivot ) j-- ;
        if ( i >= j ) break; 
            int temp = a[i] ;
            a[i] = a[j] ;
            a[j] = temp ; 
            i++; j--; 
    }
    return i;
    //return j;
}




int main()
{
    int n, pivot;
    cin >> n >> pivot;
    int * a = new int [n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int p = partition(pivot, a, n);

    for( int i = 0; i < n; i++){
        cout << a[i] << " " ;
    }
    cout << endl << p;
    return 0;
}
