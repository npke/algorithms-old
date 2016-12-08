#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << endl;
}

void quickSort(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int pivot = a[(r + l) / 2];
    
    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        
        if (i <= j)
            swap(a[i++], a[j--]);
    }
    
    if (l < j) 
        quickSort(a, l, j);
    if (r > i)
        quickSort(a, i, r);
}

int main()
{
    int a[] = {1, 3, 2, 90, 78, 45, 23, 56, 12, 69, 123, 50};
    clock_t begin = clock();
    quickSort(a, 0, 11);
    clock_t end = clock();
    cout << "Time: " << (float)(end - begin)/CLOCKS_PER_SEC<< endl;
    printArray(a, 12);
    
    return 0;
}