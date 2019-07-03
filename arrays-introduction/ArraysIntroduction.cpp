#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    scanf("%i", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        int number;
        scanf("%i", &number);
        arr[i] = number;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[n - 1 - i] << " ";
    }

    return 0;
}
