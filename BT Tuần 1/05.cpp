/* Khi tổng kết xếp hạng mà có nhiều đối tượng trùng điểm nhau thì chắc chắn thứ hạng của các đối tượng đó phải giống nhau. 
Cách cổ điển nhất để đánh thứ hạng trong trường hợp này là cho các đối tượng cùng điểm số đồng hạng với nhau và các thứ hạng sau sẽ được để trống. 
Ví dụ với 4 đối tượng lần lượt được điểm 10, 9, 9, 8 thì thứ hạng tương ứng sẽ là 1, 2, 2, 4 (không có hạng 3). 
Tuy trong toán học thống kê chúng ta còn nhiều phương pháp xếp hạng khác nhưng cách xếp hạng cổ điển này vẫn được dùng nhiều trong đời sống

Hãy viết chương trình thực hiện xếp thứ hạng cho các phần tử trong mảng số nguyên dựa trên giá trị của chúng */

#include <iostream>

using namespace std ;

int main ()
{
    int n, a[10000000] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> a[ i ] ;
    

}