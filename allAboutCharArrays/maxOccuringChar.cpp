#include <iostream>
#include <string>
#include <climits>

using namespace std;


void maxOccuringChar(char strInput[]){
    int result[26] = {0};
    for(int i=0; strInput[i] != '\0'; i++){
        char ch = strInput[i];
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a'; // Convert to lowercase
        }
        if(ch >= 'a' && ch <= 'z') {
            result[ch - 'a']++;
        }
        else{
            continue;
        }
    }

    int maxi = INT_MIN;
    int ansInd = -1;
    for(int i=0; i <= 25; i++){
        if(result[i] > maxi){
            maxi = result[i];
            ansInd = i;
        }
    }
    cout << "Max occurence character is: " << char(ansInd + 'a') << " and it's count is: " << maxi << endl;
}


int main(void){
    cout << "Enter the string: ";
    char strInput[100];
    cin.getline(strInput, 100);

    maxOccuringChar(strInput);

    return 0;
}