#include <bits/stdc++.h>

using namespace std;

string number_names[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 9) {
        cout << number_names[n - 1];
    } else {
        cout << "Greater than 9";
    }

    return 0;
}
