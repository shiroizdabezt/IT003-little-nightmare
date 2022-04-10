#include <bits/stdc++.h>

using namespace std ;

vector<string> split(string path, string delimeter) // Hàm cắt chuỗi 
{
    int s = 0 ;
    vector<string> kq ;
    while (1)
    {
        auto a = path.find(delimeter, s) ;
        if ( a== string::npos) break;
        string sub = path.substr(s, a - s ) ;
        if ( sub != "" ) kq.push_back(sub) ;
        s = a + 1 ;
    }   
    return kq;
}

int main()
{
    // absolute path which we have to simplify.
    while ( 1 ) 
    {
        string path ;
        cin >> path ;
        if ( path == "END") break; 
        auto substrings = split (path, "/" ) ;
        /* for ( auto i : substrings ) 
        {
            
        } */
        vector<string> st ;
        for ( auto x : substrings ) 
        {
            if ( x == "." ) continue;
            else if ( x == ".." ) 
            {
                if ( !st.empty())
                    st.pop_back() ;
            }
            else 
                st.push_back(x) ;
        }
        /* std::reverse(st.begin() , st.end() ) ; */
        for ( auto i : st ) 
        {
            cout << "/" << i ;
        }
        cout << "\n" ;
    }
    return 0;
}