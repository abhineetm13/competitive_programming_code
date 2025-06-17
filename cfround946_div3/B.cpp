#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// void sort(char word[], char sorted[], long int length);
int main()
{
    int t; cin >> t;
    for (int nTest = 0; nTest < t; nTest++)
    {
        long int n; cin >> n;
        char word[n];
        for(int i=0; i<n; i++) cin >> word[i];
        // for(int i=0; i<n; i++) cout << word[i];
        char sorted[n];
        // sort(word, sorted, n);
        for(int i=0; i<n; i++) sorted[i] = word[i];
        sort(sorted, sorted+n);
        // for(int i=0; i<n; i++) cout << sorted[i];
        char* newend = unique(sorted, sorted+n);
        int lsorted = (newend-sorted);
        // for(int i=0; i<lsorted; i++) cout << sorted[i];
        char final[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<lsorted; j++)
            {
                if(word[i] == sorted[j]) final[i] = sorted[lsorted-j-1];
            }
        }
        for(int i=0; i<n; i++) cout << final[i];
        cout << endl;

    }
    
}

// void sort(char word[], char sorted[], long int length)
// {
//     int lsorted = 1;
//     sorted[0] = word[0];
//     for(int i=0; i<length; i++)
//     {
//         if(word[i] > sorted[lsorted]) 
//         {
//             sorted[lsorted] = word[i];
//             lsorted++;
//         }
//         for(int j=0; j<lsorted; j++)
//         {
//             if(word[i] == sorted[j]) break;
//             else if(word[i] < sorted[j])
//             {
//                 for(int x=lsorted-1; x>j; x--)
//                 {
//                     sorted[x] = sorted[x-1];
//                 }
//                 sorted[j] = word[i];
//                 lsorted++;
//                 break;
//             }
//         }
//     }
// }