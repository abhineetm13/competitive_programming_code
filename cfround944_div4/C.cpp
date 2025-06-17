#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int nTest = 0; nTest < t; nTest++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ( a < c && c < b && (d < a || d > b) ) cout << "YES" << endl;
        else if ( b < c && c < a && (d < b || d > a) ) cout << "YES" << endl;
        else if ( a < d && d < b && (c < a || c > b) ) cout << "YES" << endl;
        else if ( b < d && d < a && (c < b || c > a) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}