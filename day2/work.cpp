#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void p1() {
    ifstream f("data.txt");

    f.close();
}

void p2() {
    ifstream f("data.txt");

    f.close();
}

int main() {
    p1();
    p2();
}