#include <iostream>
#include <cstdio>
using namespace std;

string number_names[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int main() {
    int a, b;
    scanf("%i\n%i", &a, &b);

    for (int i = a; i <= b; i++) {
        if (i <= 9) {
            cout << number_names[i - 1] << endl;
        } else if (i > 9 && i % 2 == 0) {
            cout << "even" << endl;
        } else if (i > 9 && i % 2 != 0) {
            cout << "odd" << endl;
        }
    }

    return 0;
}

