#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int nTest = 0; nTest < t; nTest++)
    {
        long long int r; cin >> r;

        long long int count = 0;
        for(long long int y = 0; y <= r; y++)
        {
            long double xmin = sqrt(r*r-y*y);
            long long int Xmin = 0;
            if (xmin != int(xmin)) 
            {
                Xmin = int(xmin) + 1;
            }
            else Xmin = int(xmin);

            long double xmax =sqrt((r+1)*(r+1)-y*y);
            long long int Xmax = 0;
            if(xmax != int(xmax))
            {
                Xmax = int(xmax);
            }
            else Xmax = int(xmax) - 1;
            // cout << y << Xmin << Xmax << endl;
            count += 4*(Xmax-Xmin+1);
        }
        cout << count-4 << endl;
    }
    
}

