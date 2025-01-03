#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int signOf(int x) {
    return (x > 0) - (x < 0); // neat trick from stack overflow, next time I gotta figure this out
}

bool isSafe(const int *row, int n) {
    if(n < 2) return true; // probably not needed

    int diff = row[0] - row[1];
    int dir = signOf(diff);
    if(dir == 0) return false; // handles edge case of first two numbers matching

    for(int j = 0; j < n - 1; j++) {
        diff = row[j] - row[j+1];
        if(signOf(diff) != dir || abs(diff) > 3)
            return false;
    }
    return true;
}

int getLength(string row) { // a quick and dirty helper function to find the number of numbers in a row
    int i = -1, count = 0;
    while(row[++i]) if(row[i] == ' ') count++;
    return count + 1; // there is one more space than number, unless we get a string with no numbers
}

int *parseLine(string row, int n) {
    // allocate a new array
    int* rowArray;
    rowArray = new int [n];

    // put the numbers in the spots
    int space;
    for(int i = 0; i < n; i++) {
        space = row.find_first_of(' ');
        rowArray[i] = stoi(row.substr(0, space));
        row.erase(0, space + 1); // gets rid of the number
    }

    // return the new array
    return rowArray;
}

void p1() {
    ifstream f("data.txt");

    int *row, length, safeReports = 0;
    string buffer;

    for(int i = 0; i < 1000; i++) {
        // turn the current row into a int array
        getline(f, buffer, '\n');
        length = getLength(buffer);
        row = parseLine(buffer, length);

        // check safety and possibly increment
        safeReports += isSafe(row, length);

        /*printf("i: %d ", i);
        if(isSafe(row, length)) {
            safeReports++;
            cout << "Safe: ";
        } else {
            cout << "Not Safe: ";
        }
        for(int k = 0; k < 5; k++) cout << row[k] << " ";
        cout << endl; */
        // de allocate dynamic memory
        delete []row;
    }

    printf("Safe Reports: %d\n", safeReports);

    f.close();
}

void p2() {
    ifstream f("data.txt");

    f.close();
}

int main() {
    // testing:
    // int a[5] = {0, 3, 4, 5, 6};
    // cout << isSafe(a, 5) << endl;

    // string b = "123 4 1 523 1 324";
    // cout << getLength(b) << endl;
    // int *t = parseLine(b, 6);

    p1();
    // p2();
}