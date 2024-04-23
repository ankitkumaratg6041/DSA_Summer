#include <iostream>

using namespace std;

void lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    cout << "Length: " << len << endl;
}

int main(void){
    cout << "Enter string: ";
    char strInput[20];
    cin >> strInput;
    cout << "Your input: " << strInput << endl;
    lengthOfString(strInput);

    return 0;
}