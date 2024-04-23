#include <iostream>

using namespace std;

int lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    return len;
}

bool isSubstringPresent(int StrCount[26], int subStrCount[26]){
    for(int i=0; i<26; i++){
        if(StrCount[i] != subStrCount[i]){
            return false;
        }
    }
    return true;
}

void caseHandler(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = (str[i] - 'A') + 'a';
        }
    }
}

void findNumberOfPermutations(char Str[], char subStr[]){
    // Requirements
    int StrLen = lengthOfString(Str);
    int subStrLen = lengthOfString(subStr);
    int countTotalPermutations = 0;

    // Conversion of all Upper Case Characters in the string and subString to lower case if any
    caseHandler(Str);
    caseHandler(subStr);


    // Step 1: Create count array for sub-string
    int countSubStr[26] = {0};
    for(int i=0; i<subStrLen; i++){
        char subStrChar = subStr[i];
        int subStrCharIndex = subStrChar - 'a';
        countSubStr[subStrCharIndex]++;
    }

    // Step 2: Create the first window
    int countStr[26] = {0};
    // Also check the corner case when len of sub-string > len of String
    int i=0;
    while(i<subStrLen && i<StrLen){
        char StrChar = Str[i];
        int StrCharIndex = StrChar - 'a';
        countStr[StrCharIndex]++;
        i++;
    }

    // Step 3: Check if the Substring == Part of String
    if(isSubstringPresent(countStr, countSubStr)){
        countTotalPermutations++;
    }

    // Step 4: Now keep shifting the window by one step all through the Str while checking permutations
    while(i < StrLen){
        char StrChar = Str[i];
        int StrCharIndex = StrChar - 'a';
        countStr[StrCharIndex]++;

        StrChar = Str[i-subStrLen];
        StrCharIndex = StrChar - 'a';
        countStr[StrCharIndex]--;

        if(isSubstringPresent(countStr, countSubStr)){
            countTotalPermutations++;
        }

        i++;
    }

    cout << "Total number of Permutations are: " << countTotalPermutations << endl;

}

int main(void){
    cout << "Enter the string: ";
    char Str[1000];
    cin.getline(Str, 1000);

    cout << "Enter the substring: ";
    char subStr[1000];
    cin.getline(subStr, 1000);

    findNumberOfPermutations(Str, subStr);

    return 0;
}