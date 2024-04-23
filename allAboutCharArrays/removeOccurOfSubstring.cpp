#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    return len;
}

void removeSubstring(char strInput[], int startPos, int lenSubString){
    // int front = i+j;
    int i;
    for(i = startPos; strInput[i+lenSubString] != '\0'; i++){
        strInput[i] = strInput[i + lenSubString];
    }
    strInput[i] = '\0';
}

void rmoveOccurOfSubstring(char strInput[], char subString[]){
    int totalSubStrPresent = 0;
    int lenStrInput = lengthOfString(strInput);
    int lenSubString = lengthOfString(subString);

    for(int i=0; i<=lenStrInput - lenSubString; i++){
        int j;
        for(j=0; j<lenSubString; j++){
            if(strInput[i+j] != subString[j]){
                break;
            }
        }
        if(j == lenSubString){
            totalSubStrPresent++;
            removeSubstring(strInput, i, j);
            i = 0; // move i to the end of substring

        }
    }
    cout << "Total number of substrings present: " << totalSubStrPresent << endl;
    cout << "Now the string looks like: " << strInput << endl;
}


int main(void){
    cout << "Enter the string: ";
    char strInput[1000];
    cin.getline(strInput, 1000);

    cout << "Enter the substring: ";
    char subString[1000];
    cin.getline(subString, 1000);

    rmoveOccurOfSubstring(strInput, subString);

    return 0;
}