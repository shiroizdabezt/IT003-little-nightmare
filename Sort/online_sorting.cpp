/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/
#include <iostream>
#include <cstring>

//###INSERT CODE HERE -
void insertion_binary_search_sort(int ms, int *a, int n)
{
    for (int i = 1; i < n; i++) 
    {
        int e = a[i]; int k;
        for (k = i-1; k>-1; k--) 
        {
            if (a[k] < e) break;
            a[k+1] = a[k];
        }
        a[k+1] = e;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int *a = new int [1000000];
    int x;
    int n = 0, ms;
    do {
        std::cin >> x;
        if (x == 0) break;
        std::cin >> ms;

        if (x == 1) insertion_binary_search_sort(ms, a, n);
        else if (x == 2) std::cout << bin_search(ms, a, n) + 1 << std::endl;
    } while (x > 0);


    return 0;
}
