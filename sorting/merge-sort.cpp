#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n = r - l + 1;
    int temp[n];
    
    int k, i = l, j = m + 1;
    for (k = 0; k < n; k++)
    {
        if (i > m)
            temp[k] = a[j++];
        else if (j > r)
            temp[k] = a[i++];
        else if (a[i] > a[j])
            temp[k] = a[j++];
        else temp[k] = a[i++];
    }
    
    for (i = l, j = 0; i <= r; i++, j++)
        a[i] = temp[j];
}

void mergeSort(int a[], int l, int r)
{
    if (l == r)
        return;
        
    int m = (l + r) / 2;
    
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    
    merge(a, l, m, r);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {10, 6, 7, 12, 2, 45, 8, 90, 55, 120, 32, 1, 1000, -1, 345, -78};
    mergeSort(a, 0, 16);
    printArray(a, 12);
    
    return 0;
}