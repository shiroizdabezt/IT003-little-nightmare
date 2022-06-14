int partition ( int *a, int pivot, int n ) 
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