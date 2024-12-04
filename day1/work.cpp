#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("data.txt");

    int a[1000], b[1000];

    for (int i = 0; i < 1000; i++) {
        f >> a[i];
        f >> b[i];
    }

    int n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n);
    sort(b, b + n);

    int sum = 0;

    for (int i = 0; i < 1000; i++) 
        sum += abs(a[i] - b[i]);

    printf("Sum: %d\n", sum);

    f.close();

    return 0;
}