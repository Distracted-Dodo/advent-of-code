#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int signOf(int x) {
    return (x > 0) - (x < 0);
}

bool isSafe(int row[]) {
    int diff = row[0] - row[1];
    int dir = signOf(diff);
    bool safe = true;

    for(int j = 0; j < 4; j++) {
        diff = row[j] - row[j+1];
        if(signOf(diff) != dir || abs(diff) > 2) {
            safe = false;
            break; // bad practice...
        }

    }
    return safe;
}
void p1() {
    ifstream f("data.txt");

    int row[5], safeReports = 0;

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 5; j++) f >> row[j];

        safeReports += isSafe(row);
    }

    printf("Safe Reports: %d\n", safeReports);

    f.close();
}

void p2() {
    ifstream f("data.txt");

    f.close();
}

int main() {
    p1();
    // p2();
}