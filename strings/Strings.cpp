#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
  
    cin >> a >> b;

    cout << a.size() << " " << b.size() << endl;

    string concatenated = a + b;
    cout << concatenated << endl;

    a[0] = b[0];
    b[0] = concatenated[0];
    cout << a << " " << b << endl;
    return 0;
}

