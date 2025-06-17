#include <iostream>

using namespace std;

void sort(long long int array[], long long int positions[],int length);
int main()
{
    int t; cin >> t;
    for( int nTest = 0; nTest < t; nTest++ )
    {
        long long int n; cin >> n;
        long long int a[n]; for(int i=0; i<n; i++) cin >> a[i];
        bool Done[n]; for(int i=0; i<n; i++) Done[i] = false;

        for(int i=0; i<n && !(Done[i]); i++)
        {
            
        } 
    }
}

void sort(long long int array[], long long int positions[],int length)
{
    for(int i=0; i<length; i++)
    {
        long long int min = positions[i];
        for(int j=i+1; j<length; j++)
        {
            if(array[positions[j]] < array[min]) min =  positions[j]; 
        }
        swap(array[positions[i]], array[positions[min]]);
    }
    return;
}