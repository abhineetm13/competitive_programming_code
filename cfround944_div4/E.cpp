#include <iostream>
// #define int long long int
using namespace std;

int search(long long int array[], int start, int end, long long int num);

signed main()
{
    int t; cin >> t;
    for (int nTest = 0; nTest < t; nTest++)
    {
        long long int n; cin >> n;
        int k; cin >> k;
        int q; cin >> q;

        long long int a[k+1]; for(int i=1; i<=k; i++) cin >> a[i];
        a[0] = 0;
        long long int b[k+1]; for(int i=1; i<=k; i++) cin >> b[i];
        b[0] = 0;

        for(int query=0; query<q; query++)
        {
            long long int d; cin >> d;
            int floor = search(a, 0, k, d);
            // cout << floor << endl;
            if(floor != k)
            {
                long long int time = b[floor] + (d-a[floor])*(b[floor+1] - b[floor])/(a[floor+1] - a[floor]) ;
                cout << time << " ";
            }
            else if (floor == k) cout << b[k] << " ";
        }
        cout << endl;
    }
    
    // int array[] = {1,3,5,7,9};
    // cout << search(array, 0, 4, 5) << endl;
}

int search(long long int array[], int start, int end, long long int num)
{
    if((end - start) > 1)
    {
        int mid = (end+start)/2;
        if(num == array[mid]) return mid;
        else if(num > array[mid]) return search(array, mid, end, num);
        else return search(array, start, mid, num);
    }
    if ((end - start) == 1)
    {
        if(array[start] <= num && num < array[end]) return start;
        else return end;
    }
    else return -1;
}