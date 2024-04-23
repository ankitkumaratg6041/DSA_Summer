#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &s, int i){

    // base case
    if(i >= s.length()-1-i){
        return true;
    }

    // processing and recursion
    if(s[i] == s[s.length()-1-i]){
        return isPalindrome(s, ++i);
    }
    else return false;

}

int main(void){
    string s;
    cout << "Enter string: ";
    cin >> s;

    // reverseString(s, 0, s.length()-1);
    bool ans = isPalindrome(s, 0);

    cout << "isPalindrome: " << ans << endl;

    return 0;
}