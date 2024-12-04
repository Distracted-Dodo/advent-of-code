#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void p1() {
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

    printf("Sum of differences: %d\n", sum);

    f.close();
}

void p2() {
    ifstream f("data.txt");

    int a[1000], b[1000];

    for (int i = 0; i < 1000; i++) {
        f >> a[i];
        f >> b[i];
    }

    int n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n);
    sort(b, b + n);

    int counts[1000];
    int start = 0, j = 0;

    for(int i = 0; i < 1000; i++) {
        counts[i] = 0;
        while(b[start] < a[i]) start++;
        while(b[start + j] == a[i]) {
            j++;
            counts[i]++;
        }
        j = 0;
    }

    int sum = 0;

    for(int i = 0; i < 1000; i++) sum += a[i] * counts[i];

    printf("Similarity score: %d\n", sum);
}

int main() {
    p1();
    p2();
}