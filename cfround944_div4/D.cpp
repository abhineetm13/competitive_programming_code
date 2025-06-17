#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t; cin >> t;
    for(int nTest = 0; nTest < t; nTest++)
    {
        char str[500];
        cin >> str; 
        int nPieces = 1;
        int l = strlen(str);
        bool joint = false;
        for(int i=0; i<(l-1); i++)
        {
            if(! joint)
            {
                if(str[i] == '0' && str[i+1] == '1') joint = true;
                else if (str[i] == '1' && str[i+1] == '0') nPieces++;
            }
            else
            {
                if(str[i] != str[i+1]) nPieces++;
            }
        }
        cout << nPieces << endl;
    }
}