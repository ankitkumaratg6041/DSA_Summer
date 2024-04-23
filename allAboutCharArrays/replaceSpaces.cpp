#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void replaceSpaces(char strInput[]){
    string result = "";
    for(int i=0; strInput[i] != '\0'; i++){
        if(strInput[i] == ' '){
            result += "@40";
        } else{
            result += strInput[i];
        }
    }


    cout << "Replaced spaces with '@40': " << result << endl;
}


int main(void){
    cout << "Enter the string: ";
    char strInput[100];
    cin.getline(strInput, 100);

    replaceSpaces(strInput);

    return 0;
}