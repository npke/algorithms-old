#include <iostream>
#include <algorithm>
using namespace std;

void bubleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {10, 6, 7, 12, 2, 45, 8, 90, 55, 120, 32, 1};
    bubleSort(a, 12);
    printArray(a, 12);
    
    return 0;
}