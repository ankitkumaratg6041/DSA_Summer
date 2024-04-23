#include <iostream>

using namespace std;

char toLowerCase(char input){
    if(input >= 'A' && input <= 'Z'){
        input = input - 'A' + 'a';
        return input;
    }
    else { 
        return input;
    }
}

bool isAlphaNumeric(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9');
}

void specialCharIgnorePalindrome(char input[], int len){
    int i=0;
    int e=len-1;

    while(i <= e){
        while(i<e && !isAlphaNumeric(input[i])) i++;
        while(e>i && !isAlphaNumeric(input[e])) e--;
        if(toLowerCase(input[i]) != toLowerCase(input[e])){
            cout << "Not a palindrome" << endl;
            return;
        }
        else {
            i++;
            e--;
        }
    }
    cout << "It is a Palindrome" << endl; 
}

void lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    specialCharIgnorePalindrome(strInput, len);
}

int main(void){
    cout << "Enter string: ";
    char strInput[100];
    // cin >> strInput;
    cin.getline(strInput, 100);
    cout << "Your input: " << strInput << endl;
    lengthOfString(strInput);

    return 0;
}