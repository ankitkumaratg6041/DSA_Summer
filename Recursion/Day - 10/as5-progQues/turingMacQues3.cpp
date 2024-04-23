#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool poundSymbolRepeatString(vector<char> stringTape, int &ind){
    for(int i=stringTape.size()-1; i>=0; i--){
        if(stringTape[i] == '#'){
            ind = i;
            return true;
        }
    }
    return false;
}

void duplicateString(vector<char>& stringTape, int start, int ind){
    int s=start; // here s is equivalent to the head of the tape
    int e= ind; // keeping e at next pos of '#';
    while(stringTape[s] != '#'){
        stringTape[e++] = stringTape[s++];
    }
}

string strRepeatTRM(string& str){
    int len = str.length();
    vector<char> stringTape((2*len)+1, 'B'); // tape for turing machine
    // loop to copy all the chars from str into the tape one by one
    for(int i=0; i<len; i++){
        stringTape[i] = str[i];
    }

    int ind = -1;
    if(poundSymbolRepeatString(stringTape, ind)){
        stringTape[len] = '#';
        duplicateString(stringTape, ind+1, len+1);
    }else{
        // inserting '#' at the end original string copied in the vector i.e. tape
        stringTape[len] = '#';
        duplicateString(stringTape, 0,len+1);
    }
    // now we need to conver our vector of char to string
    string output(stringTape.begin(), stringTape.end());
    output.erase(output.find_last_not_of('B')+1);
    return output;
}

bool isOnes(string str){
    for(char i : str){
        int num = i - '0'; // converting each char in str to int value
        if((num & 1) == 0){  // bitwize '&' to check if num is 1 or 0
            return false;
        }
    }
    return true;
}

string findNext(string str){
    vector<char> tape(str.begin(), str.end());

    if(isOnes(str)){
        // resize the tape vector and initialize it with only zeroes
        tape.resize(str.size()+1);
        int size = tape.size();
        for(int i=0; i<size; i++){
            tape[i] = '0';
        }
    }
    else{
        int i = tape.size()-1;
        while(i>=0 && tape[i] != '0'){ i--; }
        tape[i] = '1';
        for (int j = i + 1; j < tape.size(); j++){
            tape[j] = '0';
        }
    }

    string nextBinaryStringVal(tape.begin(), tape.end());
    return nextBinaryStringVal;
}

void reverseStr(string& str){
    int i=0;
    int j=str.size()-1;
    while(i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

void findFirstPoundSymbol(string currRepeatString, string& str, int &hashIndex){
    string tempString = "";
    for(int i=currRepeatString.size()-1; i>=0; i--){
        if(currRepeatString[i] != '#'){
            tempString.push_back(currRepeatString[i]);
        }
        else {
            hashIndex = i;
            str = tempString;
            break;
        }
    }
}

vector<string> generateBinaryStrings(int n){
    string str = "0";
    vector<string> binaryString;
    binaryString.push_back(str);

    while(n--){        
        string currRepeatString = strRepeatTRM(str);
        binaryString.push_back(currRepeatString);

        int hashIndex = -1;
        findFirstPoundSymbol(currRepeatString, str, hashIndex);
        reverseStr(str);
        string currNextString = findNext(str);
        int k=0;
        for(int i=hashIndex+1; i<currRepeatString.length(); i++){
            currRepeatString[i] = currNextString[k++];
        }
        while(k<currNextString.length()){
            currRepeatString = currRepeatString + currNextString[k++];
        }
        binaryString.push_back(currRepeatString);
        str = currRepeatString;
    }

    // cout << "Result: ";
    // for(auto i: binaryString){
    //     cout << i << endl;
    // }

    return binaryString;
    
}

void print(vector<string> nBinaryStrings){
    int size = nBinaryStrings.size();
    int count = -2;
    for(int i=0; i<size; i++){
        if(count == 1){
            cout << endl;
            cout << nBinaryStrings[i] << endl;
            count=0;
        }
        else{
            cout << nBinaryStrings[i] << endl;
            count++;
        }
    }
}

int main(void){
    int n;
    cout << "How many binary strings you want? ";
    cin >> n;

    vector<string> nBinaryStrings;
    nBinaryStrings = generateBinaryStrings(n);

    print(nBinaryStrings);

    return 0;
}