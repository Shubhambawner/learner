#include <iostream>
#include <string>

using namespace std;

bool f(const string& binaryStr) {
    bool foundOne = false;
    for (char bit : binaryStr) {
        if (bit == '1') {
            foundOne = true;
        } else if (bit != '0') {
            return false;
        }
    }
    return foundOne;
}

int main() {
    cout<<"333333";
    string b;
    cin >> b;
    cout << (f(b) ? "True" : "False") << endl;
}
