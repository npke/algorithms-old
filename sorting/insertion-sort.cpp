#include <iostream>
#include <algorithm>
using namespace std;

// void insertionSort(int a[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int x = a[i];
        
//         // Tìm kiếm và dời chỗ
//         int j = i - 1;
//         while (a[j] > x && j >= 0)
//         {
//             a[j+1] = a[j];
//             j--;
//         }
        
//         a[j+1] = x;
//     }
// }

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && a[i] < a[j]; j--, i--) {
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
    int a[] = {10, 6, 7, 12, 2, 45, 8, 90, 55, 120, 32, 1, 1, 0, 1, 1};
    insertionSort(a, 16);
    printArray(a, 16);
    
    return 0;
}