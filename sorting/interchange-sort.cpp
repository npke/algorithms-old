#include <iostream>
#include <algorithm>
using namespace std;

void interchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
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
    interchangeSort(a, 12);
    printArray(a, 12);
    
    return 0;
}