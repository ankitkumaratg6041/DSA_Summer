#include <iostream>

using namespace std;

char toLowerCase(char input){
    if(input >= 'a' && input <= 'z'){
        return input;
    }
    else { 
        input = input - 'A' + 'a';
        return input;
    }
}

void palindrome(char input[], int len){
    int i=0;
    int e=len-1;

    while(i <= e){
        if(toLowerCase(input[i]) != toLowerCase(input[e])){
            cout << "Not a palindrome" << endl;
            return;
        }
        i++;
        e--;
    }
    cout << "It is a Palindrome" << endl; 
}

void lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    palindrome(strInput, len);
}

int main(void){
    cout << "Enter string: ";
    char strInput[20];
    // cin >> strInput;
    cin.getline(strInput, 20);
    cout << "Your input: " << strInput << endl;
    lengthOfString(strInput);

    return 0;
}