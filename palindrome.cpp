#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;
    for (char c : str) {
        s.push(c);
    }
    
    for (char c : str) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }
    
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }
    system("pause");
    return 0;
}