/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


//###INSERT CODE HERE -
struct date
{
    int ngay;
    int thang;
    int nam;
};

/* struct list_date
{
    date *arr;
    int n;
};

void Nhap_1_ngay (date &a )
{
    cin >> a.ngay >> a.thang >> a.nam ;
}

void Xuat_1_ngay (date a )
{
     cout << a.ngay << " " << a.thang << " " << a.nam << "\n" ;
}

void Nhap_danh_sach ( list_date list ) 
{
    for (int i = 0 ; i < list.n ; i++ )
    {
        Nhap_1_ngay ( list.arr[i] ) ;
    }
}

void Xuat_danh_sach ( list_date list ) 
{
    for (int i = 0 ; i < list.n ; i++ )
    {
        Xuat_1_ngay ( list.arr[i] ) ;
        cout << endl ; 
    }
} */


void Selection_sort_nam ( date a[], int n ) 
{
    int min ;
    for ( int i = 0 ; i < n - 1 ; i++ ) 
    {
        min = i ; 
        for ( int j = i + 1 ; j < n ; j ++ )
        {
            if ( a[j].nam < a[min].nam ) 
                min = j ;
            else if ( a[j].nam == a[min].nam ) 
            {
                if ( a[j].thang < a[min].thang )
                    min = j ;
                else if ( a[j].thang == a[min].thang ) 
                    if ( a[j].ngay < a[min].ngay ) 
                        min = j ;
            }
        }
        date temp = a[i] ;
        a[i] = a[min] ;
        a[min] = temp ;
    }
}
int main() 
{
    /* list_date list ;
    cin >> list.n ;
    list.arr = new date[list.n] ;
    
    Nhap_danh_sach ( list ) ; */
    int n ; 
    cin >> n ;
    date a[100000] ;
    for ( int i = 0 ; i < n ; i++ ) 
    {
        cin >> a[i].ngay >> a[i].thang >> a[i].nam ;
    }
    Selection_sort_nam(a, n) ;
    
    /* Xuat_danh_sach ( list ) ; */
    for ( int i = 0 ; i < n ; i++ ) 
    {
        cout << a[i].ngay << " " << a[i].thang << " " << a[i].nam << "\n" ;
    }

    return 0 ;
}