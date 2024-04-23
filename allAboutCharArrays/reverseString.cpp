#include <iostream>
#include <algorithm>

using namespace std;

void reverseString(int len, char strInput[]){
    for(int i=0; i<len/2; i++){
        swap(strInput[i], strInput[len-1-i]);
    }
    cout << "Reversed string: " << strInput << endl;
}

void lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    reverseString(len, strInput);
}

int main(void){
    cout << "Enter string: ";
    char strInput[20];
    cin >> strInput;
    cout << "Your input: " << strInput << endl;
    lengthOfString(strInput);

    return 0;
}