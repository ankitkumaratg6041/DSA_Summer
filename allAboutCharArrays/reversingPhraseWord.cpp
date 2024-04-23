#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void reverseEachWord(char strInput[]){
    int prevIndex = 0;
    int lastIndex = -1;
    for(int i=0; strInput[i] != '\0'; i++){
        if(strInput[i] == ' ' || strInput[i+1] == '\0'){ // new word begins after this space
            lastIndex = (strInput[i+1] == '\0') ? i : i-1;
            while(prevIndex < lastIndex){ // to reverse each word in the phrase
                swap(strInput[prevIndex], strInput[lastIndex]);
                prevIndex++;
                lastIndex--;
            }
            prevIndex = i+1;
            while(strInput[prevIndex] == ' '){
                prevIndex++;
            }
        }
    }

    cout << "Reversed string: " << strInput << endl;
}


int main(void){
    cout << "Enter the string: ";
    char strInput[100];
    cin.getline(strInput, 100);

    reverseEachWord(strInput);

    return 0;
}