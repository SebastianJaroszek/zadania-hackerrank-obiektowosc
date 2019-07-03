#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> createArray(int arrayLength) {
    vector<int> arr;

    for (int i = 0; i < arrayLength; i++) {
        int number;
        scanf("%i", &number);
        arr.push_back(number);
    }
    return arr;
}

int main() {
    int numberOfArrays, numberOfQueries;
    scanf("%i %i", &numberOfArrays, &numberOfQueries);
    vector<vector<int>> arrayOfArrays;
    for (int i = 0; i < numberOfArrays; i++) {
        int arrayLength;
        scanf("%i", &arrayLength);
        vector<int> arr = createArray(arrayLength);
        arrayOfArrays.push_back(arr);
    }

    for (int i = 0; i < numberOfQueries; i++) {
        int x, y;
        scanf("%i %i", &x, &y);
        cout << arrayOfArrays[x][y] << endl;
    }

    return 0;
}

