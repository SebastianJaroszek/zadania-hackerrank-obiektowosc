#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    long l;
    char ch;
    float f;
    double d;

    scanf("%i %ld %c %f %lf", &i, &l, &ch, &f, &d);

    printf("%i\n%ld\n%c\n%.3f\n%.9lf", i, l, ch, f, d);

    return 0;
}

