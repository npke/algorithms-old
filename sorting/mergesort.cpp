#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int size = r - l + 1;
    int k = 0;
    int tmp[100];
    
    int i = l, j = m + 1;
    while (k < size) {
        while (i > m && j <= r) 
            tmp[k++] = a[j++];
            
        while (j > r && i <= m)
            tmp[k++] = a[i++];
            
        while (i <= m && a[i] <= a[j])
            tmp[k++] = a[i++];
            
        while (j <= r && a[j] <= a[i])
            tmp[k++] = a[j++];
    }
    
    for (int i = l, k = 0; i <= r; i++, k++) {
        a[i] = tmp[k];
    }
}


void mergeSort(int a[], int l, int r) {
    int m = (r + l) / 2;
    if (r - l > 1) {
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
    }
    
    merge(a, l, m, r);
}

 


int main() {
    
    int a[] = {10, 6, 7, 12, 2, 45, 8, 90, 55, 120, 32, 1, 1000, -1, 345, -78};
    mergeSort(a, 0, 16);

    for (int i = 0; i < 17; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}