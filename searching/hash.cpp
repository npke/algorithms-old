#include <iostream>
#include <string.h>
using namespace std;

int main() {
    
    int a[] = {1, 2, 4, 6, 7, 8, 10};
    int hash[10];
    
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < 7; i++) {
        hash[a[i] % 10] = 1;
    }
    
    int b[] = {1, 3, 4, 5, 8, 9};
    for (int i = 0; i < 6; i++) {
        int j = hash[b[i] % 10];
        if (j != -1) {
            cout << b[i] << "was found at " << j << endl;
        } else cout << b[i] << " - NOT FOUND" << endl;
    }
    
    return 0;
}