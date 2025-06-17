#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    int t; cin >> t;
    for(int nTest=0; nTest < t; nTest++)
    {
        bool canDo = false;
        char str[11]; cin >> str;
        int l = strlen(str);
        for(int i=0; i<l; i++)
        {
            if (str[i] != str[0])
            {
                char temp = str[i];
                str[i] = str[0];
                str[0] = temp;
                canDo = true;
                break;
            }
        }
        if (canDo)
        {
            cout << "YES"  << endl << str << endl;
        }
        else cout << "NO" << endl;
    }
}