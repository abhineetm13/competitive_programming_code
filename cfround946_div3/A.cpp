#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;

    for (int nTest = 0; nTest < t; nTest++)
    {
        int x; cin >> x;
        int y; cin >> y;

        int nMin = 0;
        if(y % 2 == 0)
        {
            if(x <= (7*4*y)/8) nMin = (y/2);
            else
            {
                nMin = (y/2) + (x-(7*4*y)/8)/15;
                if((x-(7*4*y)/8) % 15 != 0) nMin++;
            }
        }
        else 
        {
            if(x <= (7*4*(y-1))/8 + 11) nMin = (y/2)+1;
            else
            {
                nMin = (y/2)+1 + ((x-((7*4*(y-1))/8 + 11))/15);
                if((x-((7*4*(y-1))/8 + 11)) % 15 != 0) nMin++;
            }
        }

        cout << nMin << endl;
    }
    
}