#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    
    while (a[l] <= a[r])
    {
        cout << a[l] << "-" << a[r] << endl;
        int m = (l+r)/2;
        cout << "==>" << a[m] << endl;
        if (a[m] == x)
            return m;
            
            
        if (x > a[m])
            l = m + 1;
        if (x < a[m])
            r = m - 1;
    }
    
    return -1;
}

int main()
{
    int a[]  = {1, 2, 3, 12, 23, 45, 50, 56, 69, 78, 90, 123};
    cout << binarySearch(a, 12, 78) << endl;
    return 0;
}