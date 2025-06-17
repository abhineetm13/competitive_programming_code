#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int nTest = 0; nTest < t; nTest++)
    {
        int n; cin >> n;
        int a[n]; for(int i=0; i<n; i++) cin >> a[i];

        long long int num=0;

        for(int i=0; i<(n-2); i++)
        {
            // for(int j=(i+1); j<(n-2); j++)
            // {
            //     if(a[i] == a[j] && a[i+1] == a[j+1] && a[i+2] != a[j+2]) num++;
            //     else if(a[i] == a[j] && a[i+1] != a[j+1] && a[i+2] == a[j+2]) num++;
            //     else if(a[i] != a[j] && a[i+1] == a[j+1] && a[i+2] == a[j+2]) num++;
            // }

            for(int j=(i+1); j<(n-2); j++)
            {
                if(a[i] == a[j])
                {
                    if(a[i+1] == a[j+1]) {if(a[i+2] != a[j+2])num++;}
                    else if(a[i+2] == a[j+2]) num++;

                }
                else if(a[i+1] == a[j+1] && a[i+2] == a[j+2]) num ++;
            }
        }
        cout << num << endl;
    }
}