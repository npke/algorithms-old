## Heap Sort 

### Các định nghĩa và khái niệm 
#### Định nghĩa heap
>Heap là cấu trúc cây trong đó các node cha luôn lớn hơn các node con (gọi là max heap) hoặc các node cha luôn nhỏ hơn node con (gọi là min heap)

#### Định nghĩa cây 
*Cây nhị phân đầy đủ* (full binary tree)  
>Là cây nhị phân trong đó tất cả các  node (trừ node lá) đều có 0 hoặc 2 con.  ==> Đã  không có con thì thôi nếu có con  phải có 2 đứa (trái và phải)  

**Ví dụ**
```
           18
       /       \  
     15         30  
    /  \        /  \
  40    50    100   40
 /  \   
8   7  

          18
       /      \   
     15       30    
    /  \     /   \   
  40    50  100  40 
```

*Cây nhị phân hoàn chỉnh* (complete binary tree)  
>Là cây nhị phân trong đó tất cả các bậc đều full (có 0 hoặc 2 con).Riêng bậc cuối có thể full hoặc không full, đồng thời các node lá nằm hết về phía bên trái của cây.    

**Ví dụ**
```
           18
       /       \  
     15         30  
    /  \        /  \
  40    50    100   40
 /  \   /
8   7  9 
```
### Cài đặt Heap Sort 
* Bước 1: Tiến hành xây dựng max-heap (nếu sắp xếp tăng dần) từ mảng liệu bằng việc thực hiện thao tác heapify từ phần tử n/2 - 1 về phần tử 0.
* Bước 2: Phần tử đầu tiên a[0] lúc này sẽ là phần tử lớn nhất. Tiến hành di chuyển phần tử này về cuối mảng đồng thời chuyển phần tử cuối lên đầu swap(a[0], a[last]). 
* Bước 3: Loại phần tử cuối cùng ra khỏi mảng (đã được sắp xếp) và tiến hành heapify tại vị trí a[0] do mới có sự thay đổi ở vị trí này, lưu ý lúc này số lượng phần tử sẽ giảm đi 1. Sau đó quay lại bước 2.
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
