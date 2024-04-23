#include <iostream>
#include <string>

using namespace std;

void reverseString(string &s, int i){

    // base case
    if(i > s.length()-1-i){
        return;
    }

    // processing and recursion
    char temp;
    temp = s[i];
    s[i] = s[s.length()-1-i];
    s[s.length()-1-i] = temp;

    reverseString(s, ++i);
}

int main(void){
    string s;
    cout << "Enter string: ";
    cin >> s;

    // reverseString(s, 0, s.length()-1);
    reverseString(s, 0);

    cout << "Reversed: " << s << endl;

    return 0;
}