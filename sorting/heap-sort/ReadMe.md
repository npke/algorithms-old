## Heap Sort

#### Định nghĩa heap
>Heap là cấu trúc cây trong đó node cha luôn lớn hơn các node con (gọi là max heap) hoặc node cha luôn nhỏ hơn node con (gọi là min heap)

#### Định nghĩa cây 
* Cây nhị phân đầy đủ* (full binary tree)  
>Là cây nhị phân trong đó tất cả các  node (trừ node con) đều có 0 hoặc 2 con.  ==> Đã  không có con thì thôi nếu có con  phải có 2 đứa (trái v phải))

* Cây nhị phân hoàn chỉnh* (complete binary tree)  
>Là cây nhị phân trong đó tất cả các bậc (trừ bậc cuối có thể không full) đều full và các node lá nằm hết về phía bên trái của cây. 


```cpp
// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver program
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}
```