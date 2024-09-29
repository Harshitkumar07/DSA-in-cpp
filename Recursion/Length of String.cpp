#include<iostream>
using namespace std;

int LenStr(string s) {
    if (s == "")
        return 0;
    return 1 + LenStr(s.substr(1));
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of string: " << LenStr(s) << endl;
    return 0;
}
