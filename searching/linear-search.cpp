#include <iostream>
#include <time.h>

using namespace std;

int search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    
    return -1;
}


int search2(int a[], int n, int x)
{
    a[n] = x;
    for (int i = 0; ; i++)
    {
        if (a[i] == x)
            return i;
    }
    
    return -1;
}

int main()
{
    
    long long z = 9223372036854775809;
    long x = 9223372036854775807;
	
	cout << sizeof(x) << x << endl;
	
    int a[]  = {1, 3, 2, 90, 78, 45, 23, 56, 12, 69, 123, 50};
    clock_t begin = clock();
    int i = search(a, 12, 129);
    clock_t end = clock();
    cout << "Time: " << (double)(end - begin)/CLOCKS_PER_SEC<< endl;
    
    begin = clock();
    int j = search(a, 12, 129);
    end = clock();
    cout << "Time: " << (double)(end - begin)/CLOCKS_PER_SEC<< endl;
    
    
}