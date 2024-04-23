#include <iostream>

using namespace std;

int lengthOfString(char strInput[]){
    int len = 0;
    for(int i = 0; strInput[i] != '\0'; i++){
        len++;
    }
    return len;
}

void caseHandler(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = (str[i] - 'A') + 'a';
        }
    }
}

void removeDuplicates(char Str[], int startIndex, int lastIndex){
    int windowSize = lastIndex - startIndex;
    int i=0;
    for(i=startIndex; (Str[i+windowSize] != '\0'); i++){
        Str[i] = Str[i+windowSize];
    }
    Str[i] = '\0';
}

void removeAdjacentChars(char Str[]){
    int duplicateStartIndex = -1;
    int finalIndex = -1;
    bool toggle = false;

    for(int i=1; Str[i] != '\0'; i++){
        if((Str[i] != Str[i-1])){
            if(toggle == false)
                duplicateStartIndex = i;
            else{
                int lastIndex = i;
                removeDuplicates(Str, finalIndex, lastIndex); 
                toggle = false;
                duplicateStartIndex = i;
            }
        }
        else{
            toggle = true;
            finalIndex = duplicateStartIndex;
        }
    }


    cout << "Unique string is: "<< Str << endl;

}

int main(void){
    cout << "Enter the string: ";
    char Str[1000];
    cin.getline(Str, 1000);

    removeAdjacentChars(Str);

    return 0;
}